# 2022-2023 - PROJECT 2 - X86 RETROGAMING - TEAM 1

# Functional Specification

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<details>
<summary>📖 Table of content</summary>

- [2022-2023 - PROJECT 2 - X86 RETROGAMING - TEAM 1](#2022-2023---project-2---x86-retrogaming---team-1)
- [Functional Specification](#functional-specification)
  - [I. Overview](#i-overview)
      - [1. Project scope](#1-project-scope)
      - [2. Milestones](#2-milestones)
      - [3. The current state of Pac-Man](#3-the-current-state-of-pac-man)
        - [A. Yesterday](#a-yesterday)
        - [B. Today](#b-today)
        - [C. Tomorrow](#c-tomorrow)
  - [III. Requirements, Goals and constraints](#iii-requirements-goals-and-constraints)
  - [IV. Personas and scenario](#iv-personas-and-scenario)
      - [1. Hervé (old / nostalgic / rediscover)](#1-hervé-old--nostalgic--rediscover)
      - [2. Jessica (young / discover / kid of Hervé)](#2-jessica-young--discover--kid-of-hervé)
      - [3. Vanessa (young / rediscover / make the best score)](#3-vanessa-young--rediscover--make-the-best-score)
  - [V. Use case](#v-use-case)
  - [VI. Risks and Assumptions](#vi-risks-and-assumptions)
  - [VII. Security](#vii-security)
  - [VIII. Cost](#viii-cost)
  - [IX. Solution Overview](#ix-solution-overview)
  - [X. Evaluation criteria](#x-evaluation-criteria)
  - [Project role distribution](#project-role-distribution)
  - [Glossary](#glossary)

</details>

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

| | |
| ----- | ----- |
| Author(s) | Grégory PAGNOUX |
| Reviewer(s) | Victor LEROY |
| Created on | 11/06/2023 |
| Last updated | 11/09/2023 |

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

## I. Overview

#### 1. Project scope

![ALGOSUP logo's](img/logoALGOSUP.png)

[ALGOSUP](https://algosup.com)[^1] give the project to recreate a Pac-Man game[^2] with some twists while keeping the style of the original game, we will obviously have to get a working game before adding any changes. In order to get a better immersion, we will be using an emulator[^3] from 90's computer to run, display and play the game.

#### 2. Milestones

| Date | Deliverable |
| :-: | :-: |
| 11/13/2023 | Functional Specification |
| 11/27/2023 | Technical Specification |
| 12/08/2023 | Test plan |
| 12/11/2023 | Working prototype |
| 12/21/2023 | Final Product |
| 12/22/2023 | Presentation |

#### 3. The current state of Pac-Man

(explain PAC-MAN game)

##### A. Yesterday

Pac-Man is a game released during 1980, that was an immediate success. It is in the Top 5 of the best games from the 80's.
The game created by Tōru Iwatani[^4] was imagined for women because at this time, main players were men. For that, he implemented a game without stereotypes and with basic and neutral colors. There are also 4 ghosts including one feminal, smarter than the 3 others.

*Sources :* [Sens Critique](https://www.senscritique.com/top/resultats/les_meilleurs_jeux_video_des_annees_1980/558562) / [Janette](https://janette.lu/les-jeux-video-les-plus-emblematiques-des-annees-80/) / [Holy Gamer Z](https://www.holygamerz.com/fr/meilleurs-jeux-video-des-annees-80-quelques-noms-pour-se-rafraichir-la-memoire)

##### B. Today

It is still one of the most famous games in the world. Everyone knows the little yellow diagram and the colors of the four ghosts.
Today, we have many new games (last one is Pac-Man World Re-Pac released the 08/26/2022), a little animated serie composed of 44 episodes, and lots of by-products.

*Sources :* [Bandai Namco, new game](https://fr.bandainamcoent.eu/pac-man/infos/le-jeu-pac-man-world-re-pac-disponible-le-26-aout-2022) / [Wikipédia](https://en.wikipedia.org/wiki/Pac-Man_(TV_series)) / [Bandai Namco, by-product](https://store.bandainamcoent.eu/fr/games/brands/pac-man/?page=1)

##### C. Tomorrow

Pac-Man is the most bought game on the Atari 2600[^5], 9th on the Game Boy Advanced[^6], 3rd on mobile and is the best arcade selling. There is also Ms. Pac-Man which is the 5th most-selling arcade game.
Many new games keep getting released with tons of by-products, so Pac-Man will continue to exist for several decades.

*sources :* [Wikipédia](https://fr.wikipedia.org/wiki/Liste_des_jeux_vidéo_les_plus_vendus)

## III. Requirements, Goals and constraints

**Requirements :**

  - Windows/MacOS
  - DOSBox
  - Assembly
  - Recreate a Pac-Man game from 90's computer
  - Improve the original game

**Goals :**

- 

**Constraints :**

- Programming language : Assembly[^7]
- Emulator : DOSBox[^8]
- 16-bit processor
- Respect Pac-Man style

## IV. Personas and scenario

**Target audience**

Pac-Man is a world-wide known game and built its place in the heart of a lot of players. Our product is therefore intended to men and women, young and old people, new player and nostalgic player. Pac-Man is a PEGI 3[^9] game and an Everyone ESRB[^10].

#### 1. Hervé (old / nostalgic / rediscover)

Hervé is a nostalgic player who knows Pac-Man since its release. He is a 52 year old man. He divorced his wife 3 years ago with whom he had two children, Jessica and Nathan. He lives in a little house with a garden in Nançay and haves all nostalgic game like the Game Boy, Atari 7800[^9] or the Apple Pippin[^10].


Jessica showed him a new version of Pac-Man on her computer with new features and he wanted to try to play this game to get a flashback of the good old times he had playing it. He installs the game on his computer and launches the game. 

#### 2. Jessica (young / discover / kid of Hervé)

Jessica is 

#### 3. Vanessa (young / rediscover / make the best score)

Vanessa is

Today, Vanessa wants to rediscover an old game on her computer and found our game. The goal is always the same : eat every dots as fast as possible without getting eaten by the ghosts.

## V. Use case

![use case](img/)

## VI. Risks and Assumptions

The project has some risks :
- Too ambitious : want to improve too much the game and forgot the original game or create features unnecessary.

- Too simple : keep the original game without improvement and not enough features.
- Copyright[^11] regulations : made features which are not in compliance with the copyright law.

## VII. Security

**Copyright**

The game is under copyright protection and we need to respect some rules in compliance to the law :
- The author enjoys a perpetual, inalienable and imprescriptible right to respect for his name, his status and his work (Article L121-1)
- Must in no way interfere with the normal exploitation of the work, nor cause unjustified prejudice to the legitimate interests of the author (Article L122-5)
- The author may not prohibit the reproduction of excerpts of works for the exclusive purpose of illustration in the context of education and vocational training (Article L122-5 12°)
- Right to reproduce the game for non-profit purposes (Article L122-5-1)

*source :* [French legislature](https://www.legifrance.gouv.fr/codes/section_lc/LEGITEXT000006069414/LEGISCTA000006146349/#:~:text=L%27auteur%20jouit%2C%20sa%20vie,soixante%2Ddix%20années%20qui%20suivent.)

**Data saving**

There are three different archives depending on the type of data :
- Active database archiving where data that are no longer useful to the enterprise (for example, data on job seekers to which they have not followed up) are deleted once the reason for the study has been completed (after a maximum of two years).
- Intermediate archiving where data are saved even after the purpose of data collection has been achieved as they are still of interest to the enterprise. The duration is set by the person responsible and must be relevant to its usefulness.
- Final archiving where data that remains of great interest in the future without an end date are saved, after an upstream check.

*source :* [CNIL](https://www.cnil.fr/sites/default/files/atoms/files/guide_durees_de_conservation.pdf)[^14]

**Age**

The age to play at certain game is regulated by the PEGI limitation in Europeen Union or the ESRB in USA.
Criterias are the violence, drugs, sex or money game.

<img src="img/ESRB.jpg" alt="PEGI"/>

*source :* [Culture Game](https://www.culture-games.com/capsule-technique/pegi-le-systeme-devaluation-europeen-des-jeux-video) / [ESRB](https://www.esrb.org/)

## VIII. Cost



## IX. Solution Overview




## X. Evaluation criteria

We will consider this project a success if we have a working game coontaining the original game and some new features. Every knowledge acquired during the project will be a bonus, adding to the global success rating of the project.

## Project role distribution

| PERSON | ROLE | MAIL |
| :-: | :-: | :-: |
| Alexis LASSELIN | Project Manager | alexis.lasselin@algosup.com |
| Grégory PAGNOUX | Program Manager | gregory.pagnoux@algosup.com |
| Salaheddine NAMIR | Tech Leader | salaheddine.namir@algosup.com |
| Jason GROSSO | Senior Software Engineer | jason.grosso@algosup.com |
| Abderrazaq MAKRAN | Junior Software Engineer | abderrazaq.makran@algosup.com |
| Victor LEROY | Quality Assurance | victor.leroy@algosup.com |

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

##  Glossary

[^1]: ALGOSUP
It's a IT school in Vierzon created in 2019 by Franck JEANNIN, Natacha BOEZ and Eric LARCHEVÊQUE. The goal of the school is to form student in the companies conditions, with team work, each roles that we can find in a company. A last thing, all the program is only in english.
*source :* [ALGOSUP site](https://algosup.com)

[^2]: Pac-Man
It's a game created by Tōru Iwatani and edited by Namco in 1980 with the first arcade game and designed for women. Today, we have 32 game in arcade, flipper and console.
Pac-Man is a little circular diagram who navigate in the maze to eat all small points, but four ghosts navigate randomly in the maze and Pac-Man doesn't touch one of it. So, we have some bonus like big points, you can eat ghosts, or cherries to earn more points.
*source :* [La voie du Nord](https://www.lavoixdunord.fr/755801/article/2020-05-22/pac-man-fete-ses-40-ans-cinq-choses-que-vous-ignorez-peut-etre-sur-lui#) / [Le guide du collectionneur](https://leguideducollectionneur.fr/2017/12/22/bonus-pac-man/)

[^3]: Emulator
An emulator is a software that allows a computer system to reproduce the behavior of another computer system. It makes it possible to run programs developed for a specific architecture on a computer with a different architecture.
*source :* [Wikipédia](https://en.wikipedia.org/wiki/Emulator)

[^4]: Tōru Iwatani
Tōru Iwatani, born January 25, 1955, is a Japanese video game designer, known for the arcade game Pac-Man
*source :* [Wikipedia](https://en.wikipedia.org/wiki/Toru_Iwatani)

[^5]: Atari 2600
The Atari 2600 is a home video game console released in September 1977 by Atari, Inc.
*source :* [Wikipedia](https://en.wikipedia.org/wiki/Atari_2600)

[^6]: Game Boy Advanced
The Game Boy Advanced (GBA) is a 32-bit handheld developed by Nintendo.
*source :* [Wikipedia](https://en.wikipedia.org/wiki/Game_Boy_Advance)

[^7]: Assembly
Assembly language is low-level code that relies on a strong relationship between the instructions input using the coding language and how a machine interprets the code instructions
*source :* [Investopedia](https://www.investopedia.com/terms/a/assembly-language.asp#:~:text=Assembly%20language%20is%20low-level,recognizable%20instructions%20for%20the%20machine.)

[^8]: DOSBox
DOSBox is a DOS-emulator that uses the SDL-library which makes DOSBox very easy to port to different platforms. DOSBox has already been ported to many different platforms, such as Windows, BeOS, Linux, MacOS X...
*source :* [dosbox offical website](https://www.dosbox.com/information.php?page=0)

[^9]: PEGI (Pan-European Game Information)
The ISFE (Interactive Software Federation of Europe) founded PEGI in 2003, a system for classifying video games by age and content. The primary objective of PEGI is not restrictive, but informative. By knowing the pictograms, parents can see at a glance the nature of the content of a game and thus avoid putting unsuitable games in their children's hands.
*source :* [Culture Game](https://www.culture-games.com/capsule-technique/pegi-le-systeme-devaluation-europeen-des-jeux-video)

[^10]: ESRB (Entertainment Software Rating Board)
Since 1994, it ratings provide information about what’s in a game or app so parents and consumers can make informed choices about which games are right for their family. Ratings have 3 parts: Rating Categories, Content Descriptors, and Interactive Elements.
*source :* [ESRB](https://www.esrb.org/)

[^11]: Atari 7800
D.
*source :* []()

[^12]: Apple Pippin
D.
*source :* []()

[^13]: Copyright
D.
*source :* []()

[^14]: CNIL (Comission National Informatique & Libertés)
It's an administrative authority that has existed since January 6, 1978, and ensures the proper use and security of computer data.
*source :* [CNIL](https://www.cnil.fr/en/cnil/cnils-missions) / [Wikipédia](https://en.wikipedia.org/wiki/Commission_nationale_de_l%27informatique_et_des_libertés)
