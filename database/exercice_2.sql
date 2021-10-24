-- Donner le nom et la ville de toutes les usines.
SELECT nomu, ville FROM u;

--  Donner le numéro, le nom de toutes les usines de Genève.
SELECT * FROM u WHERE ville = 'Genève';

-- Donner les noms des fournisseurs qui approvisionnent l'usine no 2 en produit no 7.
SELECT f.nomf FROM f
INNER JOIN puf ON puf.nf = f.nf AND puf.nu = 2 AND puf.np = 7;

-- Donner le nom et la couleur des produits livrés par le fournisseur no 12.
SELECT p.nomp, p.couleur FROM p
INNER JOIN puf ON p.np = puf.np AND puf.nf = 12;

-- Donner les numéros des fournisseurs qui approvisionnent l'usine no 5 en un produit noir.
SELECT f.nomf, f.nf, p.couleur FROM f
INNER JOIN puf ON puf.nf = f.nf AND puf.nu = 5
INNER JOIN p ON p.np = puf.np
WHERE p.couleur = 'noir';

-- Donner les noms des fournisseurs qui approvisionnent une usine de Granges ou de Genève en un produit bleu.
SELECT f.nomf, u.ville, p.couleur FROM f
INNER JOIN puf ON puf.nf = f.nf
INNER JOIN u ON puf.nu = u.nu
INNER JOIN p ON p.np = puf.np
WHERE p.couleur = 'bleu' AND (u.ville = 'Granges' OR u.ville = 'Genève');

-- Donner les noms des produits livrés à une usine par un fournisseur de la même ville.
SELECT p.nomp, u.ville, f.ville FROM p
INNER JOIN puf ON puf.np = p.np
INNER JOIN f ON puf.nf = f.nf
INNER JOIN u ON puf.nu = u.nu 
WHERE u.ville = f.ville;

-- Donner les numéros des produits livrés à une usine du Locle par un fournisseur du Locle.
SELECT p.nomp FROM p
INNER JOIN puf ON puf.np = p.np
INNER JOIN u ON puf.nu = u.nu
INNER JOIN f on puf.nf = f.nf
WHERE u.ville = 'Le Locle' AND f.ville = 'Le Locle';

-- Donner les noms des usines qui ont au moins un fournisseur qui n'est pas de la même ville.
SELECT DISTINCT u.nomu FROM u
INNER JOIN puf ON puf.nu = u.nu
INNER JOIN f on puf.nf = f.nf
WHERE f.ville != u.ville;
