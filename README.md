# Movie_Book_Recommender

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

The purpose of this project is to build a library in C++ which stores list of books and movies a user has watched. The library will then be used to fine-tune an LLM recommender model to recommend customized movies or books to an end user

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

## About The Project

The project will utilize C++ to build out an application for handling the creation and addition of user movie and book libraries. The data will then be stored in a SQL database to add to later or pull data from for use in fine-tunining an LLM. The libraries will then be used to fine-tune an LLM to provide movie or book recommendations tailored to users preferences. 

### Built With
* [![Python][Python.org]][Python-url]
* [![C++][Cplusplus.com]][Cplusplus-url]
* [![PyTorch][PyTorch.org]][PyTorch-url]
* [![PostgreSQL][PostgreSQL.org]][PostgreSQL-url]

## Getting Started

### Prerequisites (In current state)

Required Libraries/Frameworks: <br>
C++ compiler (GNU C++17 was used for this project)
[Libpqxx](https://github.com/jtv/libpqxx)

Required Hardware: <br>
NVidia GPU (once LLM has been implemented)

### Installation

1. Clone the Repo
```sh
git clone https://github.com/zjshermanburke/cppTorchNN
```
2. Verify functionality by running in IDE (this project was built and run in VS code on Ubuntu)


## Usage

TBD still in progress 

## Features
- [x] Build Movie Library
- [x] Build Book Library
- [ ] Build Data Loader and Saver in C++ (Using PostgreSQL)
- [ ] Build Python PostgreSQL Data Loader 
- [ ] Determine which LLM recommender model to utilize
- [ ] Build dataloader based on LLM in Python
- [ ] Create Jupyter notebook to handle fine-tuning in Python
- [ ] Implment user feedback functionality for LLM

## License

Distributed under the Unlicense license. See `LICENSE.txt`for more information.

## Contact

Zachary Sherman-Burke - [LinkedIn](https://www.linkedin.com/in/zachary-sherman-burke-6b7589125) - zjshermanburke@gmail.com

Project Link: [https://github.com/zjshermanburke/TransferLearning_VGG19](https://github.com/zjshermanburke/TransferLearning_VGG19)


## Acknowledgments
* [Img Shields](https://shields.io)
* [Best ReadMe Template](https://github.com/othneildrew/Best-README-Template)
* [Choose an Open Source License](https://choosealicense.com)

<!-- Markdown Links and Images-->

<!-- GitHub and LinkedIn-->
[contributors-shield]: https://img.shields.io/github/contributors/zjshermanburke/FineTuningBert.svg?style=for-the-badge
[contributors-url]: https://github.com/zjshermanburke/Movie_Book_Recommender/graphs/contributors

[forks-shield]: https://img.shields.io/github/forks/zjshermanburke/Movie_Book_Recommender.svg?style=for-the-badge
[forks-url]: https://github.com/zjshermanburke/Movie_Book_Recommender/network/members

[stars-shield]: https://img.shields.io/github/stars/zjshermanburke/Movie_Book_Recommender.svg?style=for-the-badge
[stars-url]: https://github.com/zjshermanburke/Movie_Book_Recommender/stargazers

[issues-shield]: https://img.shields.io/github/issues/zjshermanburke/Movie_Book_Recommender.svg?style=for-the-badge
[issues-url]: https://github.com/github/issues/zjshermanburke/Movie_Book_Recommender.svg

[linkedin-url]: https://www.linkedin.com/in/zachary-sherman-burke-6b7589125
[linkedin-shield]: https://img.shields.io/badge/LinkedIn-blue.svg?style=for-the-badge&logo=linkedin&colorB=555


<!-- Built With Badges -->
[Cplusplus.com]: https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white
[Cplusplus-url]: https://cplusplus.com/

[Python.org]: https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54
[Python-url]: https://python.org/

<!-- [HuggingFace.com]: https://img.shields.io/badge/%F0%9F%A4%97Hugging_Face-ffd21e -->
[PyTorch.org]: https://img.shields.io/badge/PyTorch-%23EE4C2C.svg?style=for-the-badge&logo=PyTorch&logoColor=white
[PyTorch-url]: https://pytorch.org/

[PostgresSQL.org]: https://img.shields.io/badge/PostgreSQL-316192?logo=postgresql&logoColor=white
[PostgresSQL-url]: https://www.postgresql.org/
