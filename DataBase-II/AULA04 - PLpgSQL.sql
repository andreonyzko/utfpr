DO $$
BEGIN
	raise notice 'Olá mundo';
END;
$$;

-------------------------------------------------------

CREATE OR REPLACE FUNCTION ola_mundo()
RETURNS TEXT AS $$
BEGIN
	RETURN 'Olá Mundo!';
END;
$$ LANGUAGE plpgsql;

select ola_mundo();

-------------------------------------------------------

CREATE OR REPLACE FUNCTION media(num1 numeric default 2, num2 numeric default 2)
RETURNS numeric AS $$
BEGIN
	return ($1+$2) / 2;
END;
$$ LANGUAGE plpgsql;

select media(5,15);
select media();

-------------------------------------------------------

CREATE TABLE IF NOT EXISTS departamento
(
    codigo integer NOT NULL,
    nome character varying(100) NOT NULL,
    localizacao character varying(50),
	orcamento numeric(10,2) NOT NULL,
    CONSTRAINT departamento_pkey PRIMARY KEY (codigo)
);

INSERT INTO public.departamento(codigo, nome, localizacao, orcamento) VALUES 
(1,'Vendas', 'Bloco 1', 500000),
(2,'Compras', 'Bloco 1', 1500000),
(3,'Financeiro', 'Bloco 3', 30000),
(4,'TI', 'Bloco 4', 45000);


-------------------------------------------------------

CREATE OR REPLACE FUNCTION concat_campos(tupla departamento)
RETURNS TEXT AS $$
BEGIN
	RETURN tupla.codigo || ' ' || tupla.nome;
END;
$$ LANGUAGE plpgsql;

select concat_campos(departamento.*) from departamento;

-------------------------------------------------------

CREATE OR REPLACE FUNCTION hi_lo(
IN a numeric, IN b numeric, IN c numeric, OUT hi numeric, OUT lo numeric
) AS $$
BEGIN
	hi = GREATEST(a,b,c);
	lo = LEAST(a,b,c);
END;
$$ LANGUAGE plpgsql;

select * from hi_lo(1,2,3);

-------------------------------------------------------

CREATE OR REPLACE FUNCTION verifica_orcamento(id integer)
RETURNS NUMERIC AS $$
DECLARE
	v_orcamento NUMERIC = 0;
BEGIN
	SELECT orcamento INTO v_orcamento FROM departamento WHERE codigo = id;
	RETURN v_orcamento;
END;
$$ LANGUAGE plpgsql;

select verifica_orcamento(4);

-------------------------------------------------------

DO $$
BEGIN
	FOR i IN 1..10 LOOP
		raise notice 'i = %', i;
	END LOOP;
END;
$$ LANGUAGE plpgsql;

-------------------------------------------------------

DO $$
DECLARE
	depto record;
	total numeric = 0;
BEGIN

	FOR depto IN SELECT orcamento FROM departamento LOOP
		total = total + depto.orcamento;
	END LOOP;

	raise notice 'Orçamento Total: %', total;

END;
$$ LANGUAGE plpgsql;