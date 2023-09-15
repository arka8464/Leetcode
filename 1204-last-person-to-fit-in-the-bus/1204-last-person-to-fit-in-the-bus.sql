WITH WeightSum AS (
  SELECT
    person_id,
    person_name,
    weight,
    turn,
    SUM(weight) OVER (ORDER BY turn ASC) AS total_weight
  FROM Queue
)
SELECT
  person_name
FROM WeightSum
WHERE total_weight <= 1000
ORDER BY turn DESC
LIMIT 1;
