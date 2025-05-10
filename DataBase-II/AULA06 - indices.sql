DROP TABLE IF EXISTS usuario;
CREATE TABLE usuario (
    id SERIAL PRIMARY KEY,
    nome TEXT NOT NULL,
    email TEXT NOT NULL,
    status TEXT NOT NULL,
    ultimo_login TIMESTAMP NOT NULL
);

-- Inserindo registros de usuários
INSERT INTO usuario (nome, email, status, ultimo_login)
SELECT
    'Usuário ' || g,
    'user' || g || '@exemplo.com',
    CASE WHEN g % 4 = 0 THEN 'inativo' ELSE 'ativo' END,
    NOW() - (g || ' days')::INTERVAL
FROM generate_series(1, 100000) AS g;
explain analyze select * from usuario where email= 'user50000@exemplo.com';

-- criando índice sobre email na tabela usuário
create index idx_usuario_email on usuario(email);

-- consulta com uso de índice
explain analyze select * from usuario where email= 'user50000@exemplo.com';

-- Busca por último login, apenas usuário ativos
EXPLAIN ANALYZE SELECT * FROM usuario WHERE status = 'ativo' AND ultimo_login > NOW() - INTERVAL '7 days';

-- Índice parcial apenas para usuários ativo
CREATE INDEX idx_usuario_ativo_login ON usuario(ultimo_login) WHERE status = 'ativo';
EXPLAIN ANALYZE SELECT * FROM usuario WHERE NOT status = 'ativo' AND ultimo_login > NOW() - INTERVAL '7 days’;
