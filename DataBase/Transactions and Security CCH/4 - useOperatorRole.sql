SET ROLE operator; -- Troca para role auditor

-- Não Funcional: tenta fazer um cadastro de cliente, contas e transferencias
-- (a role operator tem permissão para INSERT mas não às tabelas de sequencias)
INSERT INTO clientes(nome) VALUES('Rafael');
INSERT INTO contas(cliente_id, saldo) VALUES(5, 1000);
INSERT INTO transferencias(conta_origem_id, conta_destino_id, valor) VALUES(5, 1, 100);

RESET ROLE; -- volta a role postgres
GRANT USAGE, SELECT, UPDATE ON SEQUENCE clientes_id_seq, contas_id_seq, transferencias_id_seq TO operator;
SET ROLE operator; -- Troca para role auditor

-- Funcional: tenta fazer um cadastro de cliente, contas e transferencias
-- (a role operator tem permissão para INSERT e às tabelas de sequencias)
-- Obs.: tem que rodar um por um
INSERT INTO clientes(nome) VALUES('Rafael');
INSERT INTO contas(cliente_id, saldo) VALUES(7, 1000);
INSERT INTO transferencias(conta_origem_id, conta_destino_id, valor) VALUES(7, 1, 100);

-- Funcional: faz uma consulta utilizando as três tabelas
SELECT clienteOrigem.nome as remetente, clienteDestino.nome as destinatario, t.valor, t.data
FROM transferencias t
JOIN contas contaOrigem ON contaOrigem.id = t.conta_origem_id
JOIN clientes clienteOrigem ON clienteOrigem.id = contaOrigem.cliente_id
JOIN contas contaDestino ON contaDestino.id = t.conta_destino_id
JOIN clientes clienteDestino ON clienteDestino.id = contaDestino.cliente_id;