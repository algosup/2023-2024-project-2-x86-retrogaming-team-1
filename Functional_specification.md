# Functional Specification

## Table of contents
- [Functional Specification](#functional-specification)
  - [Table of contents](#table-of-contents)
    - [1. Project role distribution](#1-project-role-distribution)
    - [2. Overview](#2-overview)
    - [3. Goals and non goals](#3-goals-and-non-goals)
    - [4. Personas and scenario](#4-personas-and-scenario)
        - [a. Hervé](#a-hervé)
        - [b. Solange](#b-solange)
        - [c. Estelle](#c-estelle)
    - [5. Use case](#5-use-case)
    - [6. What will happen for the site](#6-what-will-happen-for-the-site)
        - [Today](#today)
        - [Tomorrow](#tomorrow)
    - [7. Risks and Assumptions](#7-risks-and-assumptions)
    - [8. Development and environement and Requirements](#8-development-and-environement-and-requirements)
    - [9. Glossary](#9-glossary)

### 1. Project role distribution

| PERSON | ROLE |
| :-: | :-: |
| Nicolas MIDA | Project Manager |
| Grégory PAGNOUX | Program Manager |
| Rémy CHARLES | Tech Leader |
| Audrey Telliez | Software Engineer |
| Pierre GORIN | Quality Assurance |

### 2. Overview

![Jacobi logo](img/Jacobi-logo.jpg)

[Jacobi](http://www.jacobi.net)[^1] is a company ==developing innovative air and water filtration products== with active coals and resin. The company created by Ferdinand Adolphe Wilhelm Jacobi has been in existence since 1916 and continues to develop around the world, such as in Allemangne, Philadelphia, India and Malaysia.
Remko Goudappel, CEO of Jacobi Company, makes a point of the ==safety== of these customers and products, but also the ==respect of the environment== during each stage of production. To contribute to the success of all these goals, the company can count on these employees whose well-being within the company is also a key point in Jacobi’s success.

The company commissioned ALGOSUP to create a communication tool to ==centralize the information== to be transmitted to all employees.
Currently, the company share and send the informations via different application like Team, Email or Yammer, but also with a paper display. However, these means of communication are too numerous and even outdated. The company would like to facilitate communication and make it more modern with the digital tools that exist.
Mr. Saeed, the Project owner of the company, would like a ==simple and secure communication tool==.

sources :
 - [Jacobi Group history](https://www.jacobi.net/jacobi-history/)
 - [Jacobi Group about](https://www.jacobi.net/about/)

**Company distribution**

| PERSON | COMPANY ROLE | PROJECT ROLE | CONTACT |
| :-: | :-: | :-: | :-: |
| Mr. Remko GOUDAPPEL | CEO | *none* |  |
| Mr. Usman SAEED | Director | Project owner | usman.saeed@jacobi.net |
| Mr. Pierre PAGE | HR Manager | Content creator | pierre.page@jacobi.net |
| Ms. Karen BLANQUE | HR Assistant | Content creator | karen.blanque@jacobi.net |
| Mr. Nicolas YVELIN | Factory Manager | Content creator | nicolas.yvelin@jacobi.net |
| Mr. Samuel NEVES | Maintenance Shop Manager | On-site installation manager |  |

### 3. Goals and non goals

**Goals :**

- site very ==secure==
- digitalise the communication
- make it ==easy== to publish the content

**Non goals :**

- Do not use the screen for entertainment purposes

---
Information :
- [exchange report with Mr SAEED](report_meeting.pdf)
---

### 4. Personas and scenario

##### a. Hervé

Hervé has been Jacobi's communications director for 10 years. He is a vigorous 52 year old man. He divorced his wife 3 years ago with whom he had two children, Jessica and Nathan.

He leaves Salbris, his home, and arrives at Jacobi for 7:15 am. He turns on the two screens in the locker room and in the cafeteria. Then he goes on his computer, on the administrator account of the site, then he chooses the "Create" option and he sets each element of the scene (number of parts, widgets, text, image...) with the news of the day that his boss asked him to share with all the employees of the company the day before. Once the settings are complete, he saves the scene and shares it on both screens simultaneously.
Saving his scene will allow him to load it later if he wants to use it again and to modify it.
At 7:30 a.m., When all employees arrive at the plant, they can see the news directly when they prepare in the locker room or when they have their coffee.

##### b. Solange

Solange is 42 years old and single. She lives in Vouzeron and has been working in Jacobi since those 20 years, after leaving his BTS communication.

She arrives at her office at 7:15 a.m. Hervé, her superior, has been on vacation for three days and yesterday, he called her in an emergency. The regulations were changed for the plant employees. On the admin account, he asked her to share on the screen in the cafeteria, the scene he had already prepared by simply loading it onto the screen, but by changing the image he had put and she also corrected an error in the title that Hervé had committed. For this, she chose the "Manage" option after logging in. Then she had to create a new scene with the "Create" option in which she would write the new company guidelines and regulations. Then she shares this scene only on the screen in the locker room.

##### c. Estelle

Estelle is 39, engaged to Alan, her 36-year-old Product Manager, and they have a daughter named Amelia. Alan and Estelle go to work together after dropping their daughter off at her parents' house in Foëcy, a few blocks away.

She arrives at the factory at 7:20 a.m., goes into the locker room to put on her work clothes and goes in front of the screen to discover possible news.
On her post, Estelle has a computer that allows her, if she wishes, to have a return of the screens on the same site as Hervé, but she connects with her own employee account. This allows him to follow developments during the day without going through the changing rooms or the cafeteria and thus stay at his workstation.

### 5. Use case
![use case](img/use_case.png)

### 6. What will happen for the site

##### Today

When the administrator, logs in with his account, He has the possibility, thanks to the "scene" tab in the navigation bar, to see the scenes that are shared on the screens, manage the scenes saved on the site for reuse or even modify them. But it can also create scenes in which it can integrate basic widgets like text or images, but also optional widgets like date, time, weather or news.
Thanks to the second tab "my account" the administrator can manage the various options of his account such as his password or his email address, but he can also have access to the site setting.
The "home" tab presents the company, its history and these values. You can access the company’s main site and have the site administrators email address so that employees can contact them if a problem is observed when sharing scenes on the screens.
Of course, employees will have limited access to the site. On their phone they will only be able to access the home page and the shared scene on the screen they decide to view.

##### Tomorrow

In the future, on the amdinistrator side, it will be possible to add videos, files (PDF type) via links or QR code or to see the state of the internet network or having more color choices for scenes. We can also add the feature of decorating the scenes during the holidays with decorative frames for Christmas, Halloween or Easter.
The page may also be translated into several languages to promote the export of the website to other Jacobi production sites.

### 7. Risks and Assumptions

**the reglementation of data backups :**

There are three different archives depending on the type of data :
- ==Active database archiving== where data that are no longer useful to the enterprise (for example, data on job seekers to which they have not followed up) are deleted once the reason for the study has been completed (after a maximum of two years).
- ==Intermediate archiving== where data are saved even after the purpose of data collection has been achieved as they are still of interest to the enterprise. The duration is set by the person responsible and must be relevant to its usefulness.
- ==Final archiving== where data that remains of great interest in the future without an end date are saved, after an upstream check.

source :
 - [CNIL](https://www.cnil.fr/sites/default/files/atoms/files/guide_durees_de_conservation.pdf)[^2]

### 8. Development and environement and Requirements

  - HTML[^3]
  - CSS [^4]
  - JS [^5]
  - PHP [^6]
  - Windows/MacOS on development

---
### 9. Glossary

[^1]: Jacobi
It's an air and water purification solutions company. The company is based in Vierzon since 1956.

[^2]: CNIL (Comission National Informatique & Libertés)
It's an administrative authority that has existed since January 6, 1978, and ensures the proper use and security of computer data.

[^3]: HTML (HyperText Markup Language)
We use this language to create a web page. It's the skeleton of the page. We write all the content as well as its structure.

[^4]: CSS (Cascading Style Sheets)
This language completes HTML. It allows to format and make more ergonomic the website. It's the flesh that embellishes the skeleton.

[^5]: JS (JavaScript)
It's an object-oriented scripting language. This means that we can make the elements that make up the website dynamic. It's the muscles and joints of the site.

[^6]: PHP (Hypertext Prepositor)
It's a langage used for create dynamic web pages via HTTP server (==server-side==) but also localy.
