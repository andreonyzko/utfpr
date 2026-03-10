-- Cria a funcao transferir com parametros de remetente destinatario e valor
CREATE OR REPLACE FUNCTION transferir(origem_id int, destino_id int, valor int)
-- Retorna uma consulta (tabela com os dados da transferencia)
RETURNS TABLE(remetente TEXT, destinatario TEXT, quantidade NUMERIC, data TIMESTAMP)
AS $$
DECLARE
    saldo_remetente int;
    id_da_transferencia int;
BEGIN
    -- Cadastra a transferencia:
    INSERT INTO transferencias(conta_origem_id, conta_destino_id, valor)
    VALUES(origem_id, destino_id, valor)
    -- Guarda o id gerado no cadastro na variavel:
    RETURNING transferencias.id INTO id_da_transferencia;
   
    -- Salva o saldo da conta de origem na variavel:
    SELECT saldo INTO saldo_remetente FROM contas WHERE id = origem_id;

    -- Se a conta de origem tem o valor, debita e credita
    IF saldo_remetente >= valor THEN
        UPDATE contas SET saldo = saldo - valor WHERE id = origem_id;
        UPDATE contas SET saldo = saldo + valor WHERE id = destino_id;

    -- Se nao tem o valor, lanca uma exceção
    ELSE
        RAISE EXCEPTION 'Saldo insuficiente na conta de origem';
        -- A PRÓPRIA FUNCTION FAZ UM ROLLBACK QUANDO LANÇADO EXCEPTION
    END IF;

    -- Retorna os dados da transferencia sucessida, A PROPRIA FUNCTION ao finalizar sem exeção COMMITA
    RETURN QUERY
        SELECT clienteOrigem.nome as remetente, clienteDestino.nome as destinatario, t.valor, t.data
        FROM transferencias t
        JOIN contas contaOrigem ON contaOrigem.id = t.conta_origem_id
        JOIN clientes clienteOrigem ON clienteOrigem.id = contaOrigem.cliente_id
        JOIN contas contaDestino ON contaDestino.id = t.conta_destino_id
        JOIN clientes clienteDestino ON clienteDestino.id = contaDestino.cliente_id
        WHERE t.id = id_da_transferencia;
END
$$ LANGUAGE plpgsql;

select transferir(1, 2, 100); 
-- Roda a função e da commit, pois a conta 1 possui 1000 de saldo

select transferir(1, 2, 1001); 
-- Roda a função mas da rollback, pois a conta 1 não 1001 de saldo