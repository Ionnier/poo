example = [
    ["A", 40],
    ["B", 5],
    ["C", 10],
    ["D", 60],
    ["E", 80],
    ["F", 100],
    ["G", 2],
    ["H", 0],
    ["I", 120],
    ["asd", 123]
]

example.sort(key=lambda el: el[1], reverse=True)

# print(example)

MAX_BONUS = 20

for i in range(4, -1, -1):
    currentValue = example[i][1]
    targetValue = example[0][1]
    if (currentValue / targetValue >= 0.9):
        example[i][1] = MAX_BONUS

CURRENT_BONUS = MAX_BONUS

for i in range(0, len(example)):
    print(CURRENT_BONUS, example[i][1])
    if (example[i][1] == CURRENT_BONUS):
        continue 
    if (CURRENT_BONUS > 0):
        CURRENT_BONUS -= 1
    for j in range(i + 1, len(example)):
        if (example[j][1] / example[i][1] >= 0.95):
            example[j][1] = min(CURRENT_BONUS, example[j][1])
        else:
            break
    example[i][1] = min(example[i][1], CURRENT_BONUS)

print(example)
