-- Purpose of this file is to verify .sql files query correctly and insert works properly
INSERT INTO 
    employees
VALUES 
    (2, 'Zachary', 'Sherman-Burke', 'zjsb@gmail', '(919)555-1234', '2021-06-01', 80000.00, 'BioPharm')
ON CONFLICT DO NOTHING;

SELECT
    *
FROM
    employees