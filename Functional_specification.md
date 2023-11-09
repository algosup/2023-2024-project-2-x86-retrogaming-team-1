# 2022-2023 - PROJECT 2 - X86 RETROGAMING - TEAM 1

# Functional Specification

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<details>
<summary>📖 Table of content</summary>

- [2022-2023 - PROJECT 2 - X86 RETROGAMING - TEAM 1](#2022-2023---project-2---x86-retrogaming---team-1)
- [Functional Specification](#functional-specification)
  - [Project role distribution](#project-role-distribution)
  - [I. Overview](#i-overview)
      - [1. The Project](#1-the-project)
      - [2. The current state of Retrogaming](#2-the-current-state-of-retrogaming)
        - [A. Yesterday](#a-yesterday)
        - [B. Today](#b-today)
        - [C. Tomorrow](#c-tomorrow)
  - [II. Goals and constraints](#ii-goals-and-constraints)
  - [III. Personas and scenario](#iii-personas-and-scenario)
      - [1. Hervé](#1-hervé)
  - [IV. Use case](#iv-use-case)
  - [V. Development and environment and requirements](#v-development-and-environment-and-requirements)
  - [VI. Risks](#vi-risks)
  - [VII. Law](#vii-law)
  - [VIII. Assumptions](#viii-assumptions)
  - [Glossary](#glossary)

</details>

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

| | |
| ----- | ----- |
| Author(s) | Grégory Pagnoux |
| Reviewer(s) |  |
| Created on | 11/06/2023 |
| Last updated | 11/09/2023 |

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

## Project role distribution

| PERSON | ROLE | MAIL |
| :-: | :-: | :-: |
| Alexis LASSELIN | Project Manager | alexis.lasselin@algosup.com |
| Grégory PAGNOUX | Program Manager | gregory.pagnoux@algosup.com |
| Salaheddine NAMIR | Tech Leader | salaheddine.namir@algosup.com |
| Jason GROSSO | Senior Software Engineer | jason.grosso@algosup.com |
| Abderrazaq MAKRAN | Junior Software Engineer | abderrazaq.makran@algosup.com |
| Victor LEROY | Quality Assurance | victor.leroy@algosup.com |

## I. Overview

#### 1. The Project

![ALGOSUP logo's](img/logoALGOSUP.png)

[ALGOSUP](https://algosup.com)[^1] is an IT school located in Vierzon and the CEO of it is Mr Franck JEANNIN, with Natacha BOEZ and Eric LARCHEVÊQUE as co-founders.

The goal of this project is to recreate a Pac-Man game[^2] with some twists while keeping the style of the original game, we will obviously have to get a working game before adding any changes. In order to get a better immersion, we will be using an emulator[^3] from 90's computer to run, display and play the game.

#### 2. The current state of Retrogaming

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

## II. Goals and constraints

**Goals :**

- Recreate a Pac-Man game from 90's computer
- Improve the original game

**Constraints :**

- Programming language : Assembly[^7]
- Emulator : DOSBox[^8]
- 16-bit processor
- Respect the Pac-Man style

## III. Personas and scenario

#### 1. Hervé

Hervé has been Jacobi's communication director for 10 years. He is a vigorous 52 year old man. He divorced his wife 3 years ago with whom he had two children, Jessica and Nathan.

He leaves Salbris, his home, and arrives at Jacobi for 7:15 am. He turns on the two screens in the locker room and in the cafeteria. Then he goes on his computer, on the administrator account of the website, then he chooses the "Create" option and he sets each element of the scene (number of parts, widgets, text, image...) with the news of the day that his boss requested him to share with all the employees of the company the previous day. Once the settings are done, he saves the scene and shares it on both screens simultaneously.
Saving this scene will allow him to load it later if he wants to use it again or modify it.
At 7:30 A.M., when all the employees arrive at the plant, they can see the news directly when they prepare themselves in the locker room or when they have their coffee.

(detail more again)

## IV. Use case

![use case](img/)

## V. Development and environment and requirements

  - Windows/MacOS
  - DOSBox
  - Assembly

## VI. Risks



## VII. Law

The game is under copyright protection and we need to respect some rules in compliance to the law :
- The author enjoys a perpetual, inalienable and imprescriptible right to respect for his name, his status and his work (Article L121-1)
- Must in no way interfere with the normal exploitation of the work, nor cause unjustified prejudice to the legitimate interests of the author (Article L122-5)
- The author may not prohibit the reproduction of excerpts of works for the exclusive purpose of illustration in the context of education and vocational training (Article L122-5 12°)
- Right to reproduce the game for non-profit purposes (Article L122-5-1)

*source :* [French legislature](https://www.legifrance.gouv.fr/codes/section_lc/LEGITEXT000006069414/LEGISCTA000006146349/#:~:text=L%27auteur%20jouit%2C%20sa%20vie,soixante%2Ddix%20années%20qui%20suivent.)

## VIII. Assumptions

Conditions and resources that need to be present and accessible for the solution to work as described.

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

##  Glossary

[^1]: ALGOSUP
It's a Vierzon school's created in 2019 by Franck JEANNIN, Natacha BOEZ and Eric LARCHEVÊQUE. The goal of the school is to form student in the companies conditions, with team work, each roles that we can find in a company. A last thing, all the program is only in english.
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
