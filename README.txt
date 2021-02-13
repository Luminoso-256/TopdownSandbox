Top Down Sandbox  - tech notes!

TILE IDS:
Dirt = 1
Grass = 2
Sand = 3
Water = 4
Planks = 5


TileTexture IDS:
(yes im being lazy and copy/pasting source code.)
 tileTextures[0] = load_bitmap("res/tex/tile/dirt.png");
    must_init(tileTextures[0], "dirt");
    tileTextures[1] = load_bitmap("res/tex/tile/grass.png");
    must_init(tileTextures[1], "grass");
    tileTextures[2] = load_bitmap("res/tex/tile/sand.png");
    must_init(tileTextures[2], "sand");
    tileTextures[3] = load_bitmap("res/tex/tile/water.png");
    must_init(tileTextures[3], "water");
    tileTextures[4] = load_bitmap("res/tex/tile/leaf.png");
    must_init(tileTextures[4], "leaf");
    tileTextures[5] = load_bitmap("res/tex/tile/planks.png");
    must_init(tileTextures[5], "planks");
    tileTextures[6] = load_bitmap("res/tex/tile/mossy_stone.png");
    must_init(tileTextures[6], "moss stone");

Entity IDS: