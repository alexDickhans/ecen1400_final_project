# Global Tycoon
*Alex Dickhans ECEN1310 Final project*

## Overview

This game is a tycoon game where the goal is to attain as much wealth as possible by colonizing the planet and attaining the most "microchips".

## Game Objectives

Users can collect raw and/or processed materials to build different "factories" that can either collect or transform raw resources.

## Resource Collection

There are the following ways to collect resources in the game.

* Pickaxe
    * Users can use their pickaxe to mine any material in the game at varying rates
    * Material Mining Rates:
        * Coal: 2/s
        * Iron: 1/s
        * Gold: 0.05-0.5/s (variable rate based on mining efficency luck - randomly drawn for each whole mining duration)
        * Silca: 0.1/s
* Lvl1 Ore Miner
    * This automated miner is the simplest one in the game and can take in coal through the furnace to
    * Material Mining Rates:
        * Coal: 1/s
        * Iron: 0.8/s
        * Gold: 0.1-1.0/s (random depending on placement)
        * Silica: 0.3/s
    * Building Recipe:
        * Iron: 4.0
    * Resources Needed:
        * Coal: 0.5/s
* Lvl2 Ore Miner
    * This automated miner is the next level up and uses electricity to superpower the output
    * Material Mining Rates:
        * Coal: 4/s
        * Iron: 3/s
        * Gold: 0.5-1.0/s (random depending on placement)
        * Silica: 2.0/s
    * Building Recipe:
        * Steel: 10.0
        * Gold: 1.0
        * Computer Chips: 1.0
    * Resources Needed:
        * Power: 1kW

## Power Generation

* Generator
    * Burns coal to produce power
    * Consumes: 1 coal/s
    * Generates: 1kW
* Coal Power Plant
    * Burns coal to produce power
    * Consumes: 5 coal/s
    * Generates: 20kW
* Solar Farm
    * Collects solar power
    * Consumes: nothing
    * Generates: 10kW
* Wind Farm
    * Collects wind power, the quantity of wind 
    * Cosumes: nothing
    * Generates: 10kW-1MW (random based on wind)

## Factories

* Lvl1 Factory
    * A basic automated factory that crafts simple components from raw materials.
    * Recipes:
        * Iron Plate
            * Input: 1 Iron Ore
            * Output: 1 Iron Plate
            * Time: 1s
        * Copper Wire
            * Input: 1 Copper Ore
            * Output: 2 Copper Wire
            * Time: 1s
        * Gear
            * Input: 2 Iron Plate
            * Output: 1 Gear
            * Time: 2s
        * Basic Circuit
            * Input: 1 Iron Plate, 2 Copper Wire
            * Output: 1 Basic Circuit
            * Time: 3s
        * Concrete
            * Input: 3 Silica, 1 Water
            * Output: 1 Concrete
            * Time: 4s
    * Building Recipe:
        * Iron: 10.0
        * Copper: 5.0
    * Resources Needed:
        * Power: 2kW

* Lvl2 Factory
    * An advanced factory with an assembler robot, producing more complex products at a much faster rate.
    * Recipes:
        * Iron Plate (Fast)
            * Input: 1 Iron Ore
            * Output: 1 Iron Plate
            * Time: 0.05s   # 20x faster
        * Copper Wire (Fast)
            * Input: 1 Copper Ore
            * Output: 2 Copper Wire
            * Time: 0.05s
        * Gear (Fast)
            * Input: 2 Iron Plate
            * Output: 1 Gear
            * Time: 0.1s
        * Advanced Circuit
            * Input: 1 Steel Plate, 4 Copper Wire, 1 Basic Circuit
            * Output: 1 Advanced Circuit
            * Time: 0.15s
        * Computer Chip
            * Input: 2 Advanced Circuit, 1 Gold Ingot
            * Output: 1 Computer Chip
            * Time: 0.2s
        * Concrete (Fast)
            * Input: 3 Silica, 1 Water
            * Output: 1 Concrete
            * Time: 0.2s
        * Concrete Slab
            * Input: 2 Concrete
            * Output: 1 Concrete Slab
            * Time: 0.3s
    * Building Recipe:
        * Steel: 20.0
        * Circuit Board: 3.0
        * Concrete: 10.0
    * Resources Needed:
        * Power: 10kW
        * Lubricant: 0.2/s (for machinery operation)




## Setting up factory chains

In this game all the items are collected in a global "inventory" where all mined or processed resources are available everywhere. This also goes for materials, they can be used at any time without having to pick them up into the inventory

## Documentation

### File Tree

* include (include directory)
    * factory.h
        * Contains files to create a generalizeable factory/power generation/resource collection device (with special case needed in main needed for mining manually)
* src (source files)