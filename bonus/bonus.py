import pandas
import pathlib
import json
import math

def fillna(value, default=0):
    if math.isnan(value):
        return default
    return value


dir_path = pathlib.Path(pathlib.Path(__file__).parent)

df = pandas.read_excel(dir_path.joinpath("grupa.ods"), engine='odf')

TOTAL_COLUMN_NAME = 'Total Bonus'
NR_MATRICOL_COLUMN_NAME = 'Nr. Matricol'
NUME_COLUMN_NAME = 'Nume'
PRENUME_COLUMN_NAME = "Prenume"


del df[NUME_COLUMN_NAME]
del df[PRENUME_COLUMN_NAME]
del df["Nota Proiect 1"]
del df["Nota Proiect 2"]
del df["Nota Proiect 3"]
del df["Total Proiect"]
del df["Total Laborator"]
del df["Bonus real"]


pairs = df[[NR_MATRICOL_COLUMN_NAME, TOTAL_COLUMN_NAME]]
pairs.columns = pairs.loc[0]
pairs = pairs.drop(0)

example = pairs.to_numpy()
example = [[x[0], x[1]] for x in example]

# example = [
#     ["A", 40],
#     ["B", 5],
#     ["C", 10],
#     ["D", 60],
#     ["E", 80],
#     ["F", 100],
#     ["G", 2],
#     ["H", 0],
#     ["I", 120],
#     ["asd", 123]
# ]


example.sort(key=lambda el: el[1], reverse=True)
MAX_BONUS = 20

for i in range(4, -1, -1):
    currentValue = example[i][1]
    targetValue = example[0][1]
    if (currentValue / targetValue >= 0.9):
        example[i][1] = min(example[i][1], MAX_BONUS)
CURRENT_BONUS = MAX_BONUS

for i in range(0, len(example)):
    if (example[i][1] == CURRENT_BONUS):
        continue 
    if (CURRENT_BONUS > 0):
        CURRENT_BONUS -= 1
    for j in range(i + 1, len(example)):
        if (example[i][1] == 0):
            break
        if (example[j][1] / example[i][1] >= 0.95):
            example[j][1] = min(CURRENT_BONUS, example[j][1])
        else:
            break
    example[i][1] = min(example[i][1], CURRENT_BONUS)

builder = {}

for i in df[NR_MATRICOL_COLUMN_NAME]:
    newdf = df.set_index(NR_MATRICOL_COLUMN_NAME, append=True, drop=False).xs(i, level=1)
    del newdf[NR_MATRICOL_COLUMN_NAME]
    builder[i] = newdf.to_dict('records')[0]

import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore

cred = credentials.Certificate(dir_path.joinpath("bonus-4d63c-firebase-adminsdk-2z1jm-ee800f3b91.json"))
firebase_admin.initialize_app(cred)

db = firestore.client()

def delete_collection(coll_ref, batch_size):
    if batch_size == 0:
        return

    docs = coll_ref.list_documents(page_size=batch_size)
    deleted = 0

    for doc in docs:
        print(f"Deleting doc {doc.id} => {doc.get().to_dict()}")
        doc.delete()
        deleted = deleted + 1

    if deleted >= batch_size:
        return delete_collection(coll_ref, batch_size)

col = db.collection("poo")
# delete_collection(col, 33)

import datetime
now = datetime.datetime.now()
for index in builder:
    for key in builder[index]:
        try: 
            int(builder[index][key])
        except:
            builder[index][key] = 0
    for x in example:
        if (x[0] == index):
            builder[index]["Bonus Lab"] = x[1] / 10
            break
    builder[index]["Update time"] = str(now)
    keys = []
    for (key, value) in builder[index].items():
        if (value == 0 and "Total" not in key):
            keys.append(key)
    for x in keys:
        builder[index].pop(x, None)
    currBonus = None
    for x in example:
        if (x[0] == index):
            currBonus = x[1] / 10
            break
    if currBonus == None:
        currBonus = 0
    df = df.astype(object)
    df.loc[df[NR_MATRICOL_COLUMN_NAME] == index, 'Total Bonus'] = currBonus
    print(builder[index])
    # col.document(index.replace("/", "_")).set(builder[index])
df.to_excel(dir_path.joinpath("grupa_copy.ods"), engine="odf")
