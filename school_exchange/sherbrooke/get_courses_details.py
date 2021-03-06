from bs4 import BeautifulSoup
import requests
import regex as re

links = {
    "https://www.usherbrooke.ca/admission/fiches-cours/GCB140/statistiques-en-ingenierie/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GCB202/informatique-pour-ingenieures-et-ingenieurs/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GIF270/structures-de-donnees-et-complexite/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GIF360/probabilites-et-modelisation-de-systemes-discrets/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GIF362/mathematiques-discretes-iv/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GIF450/calcul-discret/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GIF591/probabilites-et-statistiques/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GIF590/methodes-numeriques/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GIF620/bases-de-donnees/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GIF645/programmation-concurrente/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GIF643/programmation-concurrente/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GTA311/valorisation-des-donnees-daffaires/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GTA431/manipulation-des-donnees-pour-lanalytique/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GTA531/transformation-numerique-et-intelligence-strategique/",
    "https://www.usherbrooke.ca/admission/fiches-cours/GTA631/gestion-de-la-securite-de-linformation/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IFT436/algorithmes-et-structures-de-donnees/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IFT007/atelier-dintroduction-a-latex/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IFT536/systemes-de-calcul-scientifique/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IFT599/science-des-donnees/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IFT603/techniques-dapprentissage/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IFT608/planification-en-intelligence-artificielle/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IFT615/intelligence-artificielle/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IFT630/processus-concurrents-et-parallelisme/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IMN359/outils-mathematiques-du-traitement-dimages/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IMN430/visualisation/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IMN601/reconnaissance-de-formes-et-analyse-dimages-avancee/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IMN637/reconnaissance-de-formes-et-forage-de-donnees/",
    "https://www.usherbrooke.ca/admission/fiches-cours/IMN659/analyse-de-la-video/",
    "https://www.usherbrooke.ca/admission/fiches-cours/MAT115/logique-et-mathematiques-discretes/",
    "https://www.usherbrooke.ca/admission/fiches-cours/MAT114/mathematiques-discretes/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT289/probabilites/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT389/statistique/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT390/statistique-mathematique-et-inferentielle/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT418/statistique-appliquee/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT438/statistique-computationnelle/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT489/processus-stochastiques/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT523/statistique-bayesienne/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT524/initiation-a-la-recherche-en-statistique/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT563/modeles-statistiques-lineaires/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT564/modeles-statistiques-multidimensionnels/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT619/introduction-a-la-consultation-statistique/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT639/mesure-et-probabilites/",
    "https://www.usherbrooke.ca/admission/fiches-cours/STT522/series-chronologiques/",
}

infos = []

for l in links:
    response = requests.get(l)
    soup = BeautifulSoup(response.content, "html.parser")

    title = soup.find("h1").text
    desc = soup.find("h3", text="Cible(s) de formation").find_next("p").text
    content = soup.find("h3", text="Contenu").find_next("p").text
    cycle = soup.find("dt", text="Cycle").find_next("dd").text
    credits = soup.find("dt", text="Cr??dits").find_next("dd").text
    faculty = soup.find("dt", text="Facult??/Centre").find_next("dd").text
    charge = soup.find(
        "dt", text="R??partition de la charge de travail")

    desc = re.sub(r"\s+", " ", desc)
    content = re.sub(r"\s+", " ", content)

    html_infos = {
        "title": title,
        "link": l,
        "desc": desc,
        "content": content,
        "cycle": cycle,
        "credits": credits,
        "faculty": faculty,
    }

    if charge:
        html_infos['charge'] = charge.find_next("dd").text

    infos.append(html_infos)
    print(html_infos)

str_infos = "# D??tails des cours  \n\n"
for i in infos:
    str_infos += f"## {i['title']}  \n"
    str_infos += f"### Lien  \n"
    str_infos += f"[{i['link']}]({i['link']})  \n"
    str_infos += f"### Cible(s) de formation  \n"
    str_infos += f"{i['desc']}  \n"
    str_infos += f"### Contenu  \n"
    str_infos += f"{i['content']}  \n"
    str_infos += f"### Cycle  \n"
    str_infos += f"{i['cycle']}  \n"
    str_infos += f"### Cr??dits  \n"
    str_infos += f"{i['credits']}  \n"
    str_infos += f"### Facult??  \n"
    str_infos += f"{i['faculty']}  \n"

    if "charge" in i:
        str_infos += f"### R??partition de la charge de travail  \n"
        str_infos += f"{i['charge']}  \n"

    str_infos += f"  \n\n"

f = open("./courses_list_details.md", "w")
f.write(str_infos)
f.close()
