Top Down Sandbox  - tech notes!


Architecture:
Each entity/tile has three functions:
init() - load textures/variables ETC on spawn/load. Each object keeps their textures encapsulated because texture indices are dumb
tick() - called every frame, with keyboard params. This is where logic, AI, collisions, stat handling, etc happy
render() - adds to the renderQueue

important fields:
each entity/tile also has a modificationQueue, which is a list of type Modification, where modification is a struct describing a modification to the world. this prevent s the need for the container to pass it's state to the contained.

World class holds tiles and entities
World is resposible for adding/removing tiles, and killing/spawning entities









TILE IDS:
Dirt = 1
Grass = 2
Sand = 3
Water = 4
Planks = 5


Entity IDS: