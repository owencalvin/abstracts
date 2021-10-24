-- \c <bdd>
-- SET search_path TO <bdd>
-- \d <table_name>

SELECT * FROM supplier WHERE fax IS NULL;
SELECT * FROM product WHERE unitprice < 10;
SELECT DISTINCT country FROM customer WHERE id < 20;
SELECT contactname, city FROM supplier WHERE country='Germany';
SELECT * FROM supplier WHERE fax NOT LIKE '(313)%';
SELECT lastname, firstname FROM customer WHERE lastname LIKE 'B%';
SELECT productname FROM product WHERE unitprice < 10;
