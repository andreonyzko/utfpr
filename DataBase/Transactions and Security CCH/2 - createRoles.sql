-- Cria um usuário auditor com senha
-- com permissão só de SELECT
CREATE ROLE auditor LOGIN PASSWORD 'auditor123';
GRANT SELECT ON clientes, contas, transferencias TO auditor;

-- Cria um usuário operator com senha
-- com permissão de INSERT e SELECT
CREATE ROLE operator LOGIN PASSWORD 'operator123';
GRANT INSERT, SELECT ON clientes, contas, transferencias TO operator;

-- Da permissão para ambos usuários conectarem ao banco
GRANT CONNECT ON DATABASE "cch-db2" TO operator, auditor;