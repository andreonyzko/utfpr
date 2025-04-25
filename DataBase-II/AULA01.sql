CREATE OR REPLACE FUNCTION atualizar_updateat()
RETURNS TRIGGER AS $$
BEGIN
	IF NEW.status != OLD.status OR NEW.total != OLD.total THEN
		NEW.updated_at := NOW();
	END IF;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tg_update_timestamp
BEFORE UPDATE ON pedidos
FOR EACH ROW
EXECUTE FUNCTION atualizar_updateat();





CREATE OR REPLACE FUNCTION atualizar_qntd()
RETURNS TRIGGER AS $$
BEGIN
	IF NEW.status == 'cancelado' THEN
		NEW.quantidade = 0;
	END IF;
	RETURN NEW;
END
$$ LANGUAGE plpgsql;

CREATE TRIGGER tg_atualizar_qntd
BEFORE UPDATE ON pedidos
FOR EACH ROW
EXECUTE FUNCTION atualizar_qntd();






CREATE OR REPLACE FUNCTION backup_delete()
RETURNS TRIGGER AS $$
BEGIN
	INSERT INTO pedidos_backups 
	VALUES(OLD.id, 
	OLD.cliente, 
	OLD.status, 
	OLD.quantidade, 
	OLD.updated_at, 
	NOW());

	RETURN OLD;
END
$$ LANGUAGE plpgsql;

CREATE TRIGGER tg_backup_delete
BEFORE DELETE ON pedidos
FOR EACH ROW
EXECUTE FUNCTION backup_delete();










CREATE OR REPLACE FUNCTION verifica_quantidade()
RETURNS TRIGGER AS $$
BEGIN
	IF NEW.quantidade < 0 THEN
	RAISE EXCEPTION 'Não é possível cadastrar quantidades negativas';
	END IF;
END
$$ LANGUAGE plpgsql;

CREATE TRIGGER tg_verifica_quantidade
BEFORE INSERT OR UPDATE ON pedidos
FOR EACH ROW
EXECUTE FUNCTION verifica_quantidade();

--------------------------------------