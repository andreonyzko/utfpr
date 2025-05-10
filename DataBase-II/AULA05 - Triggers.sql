CREATE TABLE pedidos (
    id SERIAL PRIMARY KEY,
    cliente TEXT NOT NULL,
    produto TEXT NOT NULL,
    quantidade INT NOT NULL,
    status TEXT DEFAULT 'em aberto'
);


CREATE TABLE log_pedidos (
    id SERIAL PRIMARY KEY,
    pedido_id INT,
    usuario TEXT,
    data_alteracao TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    dados_antes JSONB,
    dados_depois JSONB
);

--Criando a função da trigger
CREATE OR REPLACE FUNCTION registrar_log_update_pedido()
RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO log_pedidos (
        pedido_id,
        usuario,
        dados_antes,
        dados_depois
    ) VALUES (
        OLD.id,
        SESSION_USER,
        to_jsonb(OLD),
        to_jsonb(NEW)
    );

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;


-- Criando a trigger
CREATE TRIGGER trg_log_update_pedido
AFTER UPDATE ON pedidos
FOR EACH ROW
EXECUTE FUNCTION registrar_log_update_pedido();


-- Inserindo um pedido:
INSERT INTO pedidos (cliente, produto, quantidade)
VALUES ('João Silva', 'Notebook', 1);


-- Atualizando o pedido:
UPDATE pedidos
SET quantidade = 2, status = 'pago'
WHERE id = 1;
SELECT * FROM pedidos;
SELECT * FROM log_pedidos;

-- Padronizar o nome do cliente (com BEFORE INSERT/UPDATE)
CREATE OR REPLACE FUNCTION padronizar_nome_cliente()
RETURNS TRIGGER AS $$
BEGIN
  NEW.cliente := INITCAP(NEW.cliente);  -- Padroniza estilo de nome
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_padroniza_cliente
BEFORE INSERT OR UPDATE ON pedidos
FOR EACH ROW
EXECUTE FUNCTION padronizar_nome_cliente();

-- Antes, criar campo updated_at em pedidos
alter table pedidos add column updated_at timestamp;

CREATE OR REPLACE FUNCTION atualiza_data_modificacao()
RETURNS TRIGGER AS $$
BEGIN
  NEW.updated_at := NOW();  -- Marca timestamp da alteração
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_data_modificacao
BEFORE UPDATE ON pedidos
FOR EACH ROW
EXECUTE FUNCTION atualiza_data_modificacao();

-- Impedir exclusão de pedidos já pagos (BEFORE DELETE)
CREATE OR REPLACE FUNCTION impedir_delete_pago()
RETURNS TRIGGER AS $$
BEGIN
  IF OLD.status = 'pago' THEN
    RAISE EXCEPTION 'Não é permitido excluir pedidos com status "pago".';
  END IF;
  RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_bloqueia_delete_pago
BEFORE DELETE ON pedidos
FOR EACH ROW
EXECUTE FUNCTION impedir_delete_pago();

-- Selecione um pedido existente e pago.
delete from pedidos where id = 1;
