SELECT movies.title
FROM movies
JOIN stars
ON movies.id = stars.movie_id
JOIN people
ON stars.person_id = people.id
WHERE people.name LIKE "Johnny Depp"

INTERSECT

SELECT movies.title
FROM movies
JOIN stars
ON movies.id = stars.movie_id
JOIN people
ON stars.person_id = people.id
WHERE people.name LIKE "Helena Bonham Carter"
ORDER BY movies.title ASC;

