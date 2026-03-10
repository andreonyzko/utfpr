-- Voltando a role postgres
RESET ROLE;

-- Remove todas as permissões do auditor e do operator sobre as tabelas de sequencia
REVOKE ALL ON
clientes_id_seq, contas_id_seq, transferencias_id_seq
FROM auditor, operator;

-- Remove todas as permissões do auditor e do operator sobre as demais tabelas
REVOKE ALL ON
clientes, contas, transferencias
FROM auditor, operator;

-- Remove a permissão de conexão do auditor e operator
REVOKE CONNECT ON DATABASE "cch-db2" FROM auditor, operator;

-- Deleta as roles
DROP ROLE auditor, operator;