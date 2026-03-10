-- Cria as tabelas
CREATE TABLE clientes (
 id SERIAL PRIMARY KEY,
 nome TEXT NOT NULL
);


CREATE TABLE contas (
 id SERIAL PRIMARY KEY,
 cliente_id INTEGER REFERENCES clientes(id),
 saldo NUMERIC(12,2) NOT NULL
);

CREATE TABLE transferencias (
 id SERIAL PRIMARY KEY,
 conta_origem_id INTEGER REFERENCES contas(id),
 conta_destino_id INTEGER REFERENCES contas(id),
 valor NUMERIC(12,2) NOT NULL,
 data TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Popula as tabela
INSERT INTO clientes(nome) VALUES('Evandro');
INSERT INTO clientes(nome) VALUES('Andre');
INSERT INTO clientes(nome) VALUES('Samuel');
INSERT INTO clientes(nome) VALUES('Eduardo');

INSERT INTO contas(cliente_id, saldo) VALUES(1,1000);
INSERT INTO contas(cliente_id, saldo) VALUES(2,1000);
INSERT INTO contas(cliente_id, saldo) VALUES(3,1000);
INSERT INTO contas(cliente_id, saldo) VALUES(4,1000);

-- Consulta os dados inseridos
SELECT cli.nome, c.id, c.saldo FROM clientes cli JOIN contas c ON c.cliente_id = cli.id;