# Global Tycoon
*Alex Dickhans ECEN1310 Final project*

## Overview

This game is a tycoon game where the goal is to grow wealth by developing the planet and producing **computer chips** (the end-game “microchip” product referenced in the win condition).

The sections below describe the **intended design** for mechanics and content. The current C codebase is a scaffold (inventory, resources, factories, **smelter**, and power as modular types); gameplay will be built on top of this structure.

## Game objectives

Collect raw materials (including **iron ore**), supply **fuel** or **power** where required, and build **smelters**, **factories**, and **miners** so **iron ore** and other ores become plates, wire, steel, circuits, and chips. Higher tiers need steel, advanced circuits, and more power.

## How the systems connect (flow)

1. **Early economy:** Mine **coal**, **iron ore**, **gold ore**, **silica**, and **copper ore** (pickaxe and/or **Lvl1 ore miner**). Burn coal in a **generator** for early **kW** if you skip straight to electric buildings.
2. **Smelting:** Build a **smelter** to turn **iron ore** into **iron plates**, **copper ore** into **copper wire**, **gold ore** into **gold ingots**, and **iron plates** into **steel plates**. Smelting uses **coal** (burner), not grid power.
3. **Tier 1 industry:** Build a **Lvl1 factory** to assemble **gears**, **basic circuits**, and **concrete** from plates, wire, and silica.
4. **Tier 2 industry:** Build a **Lvl2 factory** for **advanced circuits** and **computer chips**, plus faster assembly recipes. It needs **grid power** only; scale **coal plant**, **solar**, or **wind** for **10 kW** and headroom.
5. **Tier 2 mining:** Spend **steel plates**, **gold**, and **computer chips** on a **Lvl2 ore miner** once chips are flowing. The miner needs **electricity** (e.g. 1 kW), not coal like the Lvl1 miner.
6. **Global stock:** Everything produced or mined goes into one **global inventory**; recipes and build costs check that pool—no per-building chests or manual “pick up” step.

**Dependency check:** The **Lvl2 factory** build cost does *not* include chips, so you can reach **computer chips** before the **Lvl2 miner**. The miner is an optional accelerator fed by the chip line, not a prerequisite for it.

## Resource collection

Ways to obtain solid materials (all mining outputs use explicit **ore** names where applicable):

* **Pickaxe (manual mining)**
    * Mine any mineable material at varying rates.
    * Rates:
        * Coal: 2/s
        * **Iron ore:** 1/s
        * **Gold ore:** 0.05–0.5/s (random per full mining session, “mining efficiency” roll)
        * **Copper ore:** 0.5/s
        * Silica: 0.1/s
* **Lvl1 ore miner**
    * Automated miner powered by **coal** (e.g. onboard burner consuming **0.5 coal/s**).
    * Rates:
        * Coal: 1/s
        * **Iron ore:** 0.8/s
        * **Gold ore:** 0.1–1.0/s (random by placement)
        * **Copper ore:** 0.4/s
        * Silica: 0.3/s
    * Build cost:
        * **Iron ore:** 4.0
    * Operating cost:
        * Coal: 0.5/s
* **Lvl2 ore miner**
    * Faster miner that runs on **electricity** instead of coal.
    * Rates:
        * Coal: 4/s
        * **Iron ore:** 3/s
        * **Gold ore:** 0.5–1.0/s (random by placement)
        * **Copper ore:** 2/s
        * Silica: 2.0/s
    * Build cost:
        * Steel plate: 10.0
        * **Gold ore:** 1.0 (use **gold ingots** instead if your implementation smelts before placing)
        * Computer chip: 1.0
    * Operating cost:
        * Power: 1 kW

## Power generation

* **Generator**
    * Burns coal for power.
    * Consumes: 1 coal/s  
    * Generates: 1 kW
* **Coal power plant**
    * Larger coal-fired plant.
    * Consumes: 5 coal/s  
    * Generates: 20 kW
* **Solar farm**
    * Passive solar collection.
    * Consumes: nothing  
    * Generates: 10 kW (steady daytime profile is up to implementation)
* **Wind farm**
    * Passive wind collection; output varies with **wind strength** (world/placement RNG or a simple wind model).
    * Consumes: nothing  
    * Generates: 10 kW–1 MW

Grid **load** should sum miners, factories, plants, and **electric smelters** so the player balances **fuel chains** (coal → kW / coal → plates) vs **renewables**.

## Smelting

**Smelters** refine ores and metals. **Iron ore** is only consumed here (and in build costs), not in assemblers—factories work from **iron plates** and other intermediates.

### Burner smelter

Coal-fired building; no grid power required.

* **Iron plate** — Input: **1 iron ore** — Output: 1 iron plate — Time: 3.2 s — Fuel: 0.25 coal per plate (tune as needed)
* **Copper wire** — Input: **1 copper ore** — Output: 2 copper wire — Time: 1 s — Fuel: 0.1 coal per craft
* **Gold ingot** — Input: **1 gold ore** — Output: 1 gold ingot — Time: 2 s — Fuel: 0.2 coal per ingot
* **Steel plate** — Input: **5 iron plates** (smelted from **iron ore** above) + **10 coal** — Output: 1 steel plate — Time: 4 s

Build cost (example):

* **Iron ore:** 5.0  
* Coal: 10.0  

### Electric smelter (upgrade)

Same recipes as the burner smelter, but consumes **grid power** instead of recipe coal (except keep coal only for the **steel plate** chemical fuel if you want realism), at higher throughput—for example **20×** faster **iron plate** and **copper wire** steps than the burner smelter. Exact kW is up to balance; treat it as the smelting counterpart to the **Lvl2 factory** line.

## Factories (assemblers)

Assemblers take **smelter** outputs (plates, wire, ingots) and other **solid** inputs (e.g. silica)—not raw **iron ore**.

* **Lvl1 factory**  
    * Recipes:
        * **Gear** — Input: 2 iron plate — Output: 1 gear — Time: 2 s  
        * **Basic circuit** — Input: 1 iron plate, 2 copper wire — Output: 1 basic circuit — Time: 3 s  
        * **Concrete** — Input: 4 silica — Output: 1 concrete — Time: 4 s  
    * Build cost:
        * **Iron ore:** 10.0  
        * **Copper ore:** 5.0  
    * Operating cost:
        * Power: 2 kW

* **Lvl2 factory**  
    * Recipes:
        * **Gear (fast)** — Input: 2 iron plate — Output: 1 gear — Time: 0.1 s  
        * **Advanced circuit** — Input: 1 steel plate, 4 copper wire, 1 basic circuit — Output: 1 advanced circuit — Time: 0.15 s  
        * **Computer chip** — Input: 2 advanced circuit, 1 gold ingot — Output: 1 computer chip — Time: 0.2 s  
        * **Concrete (fast)** — Input: 4 silica — Output: 1 concrete — Time: 0.2 s  
        * **Concrete slab** — Input: 2 concrete — Output: 1 concrete slab — Time: 0.3 s  
    * Build cost:
        * Steel plate: 20.0  
        * Advanced circuit: 3.0  
        * Concrete: 10.0  
    * Operating cost:
        * Power: 10 kW  

## Setting up factory chains

Production and consumption use a **single global inventory** of items. Anything mined or crafted is available everywhere; buildings do not hold private stock. When implementing simulation ticks, resolve **power capacity** and **fuel** (for burner buildings) in a defined order so behavior is predictable (document that order in code comments or here).

**Iron ore** enters the chain from mining, becomes **iron plates** (and later **steel**) only in **smelters**, then feeds **factories**.

## Documentation

### File tree (planned layout)

* `include/` — public headers  
    * `factory/factory.h` — factory create/destroy API (future: rates, tier).  
    * `factory/recipe.h` — recipe create/destroy API (future: inputs, outputs, craft time).  
    * `smelter/smelter.h` — smelter create/destroy API (future: ore→plate, steel, gold).  
    * `inventory/resources.h` — resource entities or item types (future).  
    * `inventory/inventory.h` — global item storage (future: counts, caps).  
    * `inventory/power.h` — power grid / generation and load (future).  
    * `misc/utils.h` — UI helpers (e.g. clear screen, clean exit).  
    * `misc/help.h` — in-game help text.  
* `src/` — implementations matching the headers above (`main.c` entry point).

Build with `make` (see `Makefile` for objects and flags).
