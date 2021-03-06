# reone

[![Build Status](https://travis-ci.com/seedhartha/reone.svg?branch=master)](https://travis-ci.com/seedhartha/reone)

reone is a free and open source game engine, capable of running Star Wars: Knights of the Old Republic and its sequel, The Sith Lords. The project goal is to create an engine that is modern, portable and very extensible.

Currently, reone has functional resource management, rendering, audio, GUI, scripting and networking subsystems – actual gameplay implementation is very limited. See project [gallery](https://github.com/seedhartha/reone/wiki/Gallery) and [roadmap](https://github.com/seedhartha/reone/wiki/Roadmap) in the Wiki.

You must legally own a game to run it using reone – we do not endorse piracy.

## Installation

Those wishing to test reone, can either download a prebuilt executable from the [releases](https://github.com/seedhartha/reone/releases) page, or build it from source. Building it requires a modern C++ compiler and a set of free and open source libraries. See detailed instructions for your operating system [here](https://github.com/seedhartha/reone/wiki/Installation).

Install [Visual C++ Redistributable](https://aka.ms/vs/16/release/vc_redist.x64.exe) to run prebuilt Windows executables.

## Usage

Specify a game path to run the game, e.g. `reone --game C:\swkotor`

Controls:
* Use WASD keys to move around
* Click on doors to open them
* Press V to toggle camera mode

## Configuration

reone can be configured from either a command line or a configuration file. Configuration file, named "reone.cfg", must be located in the current directory. See complete list of options [here](https://github.com/seedhartha/reone/wiki/Program-options).

## Contribution

reone is in the early stages of development at the moment, meaning that the codebase is not entirely stable. Nevertheless, the project is open to potential contributors. Take a look at the [roadmap](https://github.com/seedhartha/reone/wiki/Roadmap) and [development](https://github.com/seedhartha/reone/wiki/Development) pages in the Wiki if you want to contribute.
