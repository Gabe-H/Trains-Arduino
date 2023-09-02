#ifndef ROUTES_H
#define ROUTES_H

struct Route
{
    int start;
    int end;
    int distance;
};

enum Cities
{
    Vancouver,
    Seattle,
    Portland,
    SanFrancisco,
    LosAngeles,
    Calgary,
    Helena,
    SaltLakeCity,
    LasVegas,
    Phoenix,
    Winnipeg,
    Denver,
    SantaFe,
    ElPaso,
    Duluth,
    Omaha,
    KansasCity,
    OklahomaCity,
    Dallas,
    Houston,
    SaultStMarie,
    Chicago,
    SaintLouis,
    LittleRock,
    NewOrleans,
    Toronto,
    Pittsburgh,
    Nashville,
    Montreal,
    Boston,
    NewYork,
    Washington,
    Raleigh,
    Atlanta,
    Charleston,
    Miami
};

#define NUM_CITIES 36

Route routes[78] = {
    {Vancouver, Seattle, 1},         //  0 - Vancouver - Seattle
    {Seattle, Portland, 1},          //  1 - Seattle - Portland
    {Portland, SanFrancisco, 5},     //  2 - Portland - San Francisco
    {SanFrancisco, LosAngeles, 3},   //  3 - San Francisco - Los Angeles
    {LosAngeles, ElPaso, 6},         //  4 - Los Angeles - El Paso
    {Vancouver, Calgary, 3},         //  5 - Vancouver - Calgary
    {Seattle, Calgary, 4},           //  6 - Seattle - Calgary
    {Seattle, Helena, 6},            //  7 - Seattle - Helena
    {Seattle, SaltLakeCity, 6},      //  8 - Portland - Salt Lake City
    {SanFrancisco, SaltLakeCity, 5}, //  9 - San Francisco - Salt Lake City
    {LasVegas, SaltLakeCity, 3},     // 10 - Las Vegas - Salt Lake City
    {LosAngeles, LasVegas, 2},       // 11 - Los Angeles - Las Vegas
    {LosAngeles, Phoenix, 3},        // 12 - Los Angeles - Phoenix
    {Phoenix, ElPaso, 3},            // 13 - Phoenix - El Paso
    {Phoenix, SantaFe, 3},           // 14 - Phoenix - Santa Fe
    {Phoenix, Denver, 5},            // 15 - Phoenix - Denver
    {SaltLakeCity, Denver, 3},       // 16 - Salt Lake City - Denver
    {SaltLakeCity, Helena, 3},       // 17 - Salt Lake City - Helena
    {Calgary, Helena, 4},            // 18 - Calgary - Helena
    {Calgary, Winnipeg, 6},          // 19 - Calgary - Winnipeg
    {Helena, Winnipeg, 4},           // 20 - Helena - Winnipeg
    {Helena, Duluth, 6},             // 21 - Helena - Duluth
    {Helena, Omaha, 5},              // 22 - Helena - Omaha
    {Helena, Denver, 4},             // 23 - Helena - Denver
    {Denver, Omaha, 4},              // 24 - Denver - Omaha
    {Denver, KansasCity, 4},         // 25 - Denver - Kansas City
    {Denver, OklahomaCity, 4},       // 26 - Denver - Oklahoma City
    {Denver, SantaFe, 2},            // 27 - Denver - Santa Fe
    {SantaFe, OklahomaCity, 3},      // 28 - Santa Fe - Oklahoma City
    {SantaFe, ElPaso, 2},            // 29 - Santa Fe - El Paso
    {ElPaso, OklahomaCity, 5},       // 30 - El Paso - Oklahoma City
    {ElPaso, Dallas, 4},             // 31 - El Paso - Dallas
    {ElPaso, Houston, 6},            // 32 - El Paso - Houston
    {Houston, Dallas, 1},            // 33 - Houston - Dallas
    {Dallas, OklahomaCity, 2},       // 34 - Dallas - Oklahoma City
    {OklahomaCity, KansasCity, 2},   // 35 - Oklahoma City - Kansas City
    {KansasCity, Omaha, 1},          // 36 - Kansas City - Omaha
    {Omaha, Duluth, 2},              // 37 - Omaha - Duluth
    {Duluth, Winnipeg, 4},           // 38 - Duluth - Winnipeg
    {Winnipeg, SaultStMarie, 6},     // 39 - Winnipeg - Sault St. Marie
    {Duluth, SaultStMarie, 3},       // 40 - Duluth - Sault St. Marie
    {Duluth, Toronto, 6},            // 41 - Duluth - Toronto
    {Duluth, Chicago, 3},            // 42 - Duluth - Chicago
    {Omaha, Chicago, 4},             // 43 - Omaha - Chicago
    {KansasCity, SaintLouis, 2},     // 44 - Kansas City - Saint Louis
    {OklahomaCity, LittleRock, 2},   // 45 - Oklahoma City - Little Rock
    {Dallas, LittleRock, 2},         // 46 - Dallas - Little Rock
    {Houston, NewOrleans, 2},        // 47 - Houston - New Orleans
    {NewOrleans, LittleRock, 3},     // 48 - New Orleans - Little Rock
    {LittleRock, SaintLouis, 2},     // 49 - Little Rock - Saint Louis
    {SaintLouis, Chicago, 2},        // 50 - Saint Louis - Chicago
    {Chicago, Toronto, 4},           // 51 - Chicago - Toronto
    {SaultStMarie, Toronto, 2},      // 52 - Sault St. Marie - Toronto
    {SaultStMarie, Montreal, 5},     // 53 - Sault St. Marie - Montreal
    {Toronto, Montreal, 3},          // 54 - Toronto - Montreal
    {Montreal, Boston, 2},           // 55 - Montreal - Boston
    {Toronto, Pittsburgh, 2},        // 56 - Toronto - Pittsburgh
    {Montreal, NewYork, 3},          // 57 - Montreal - New York
    {Boston, NewYork, 2},            // 58 - Boston - New York
    {Chicago, Pittsburgh, 3},        // 59 - Chicago - Pittsburgh
    {Pittsburgh, NewYork, 2},        // 60 - Pittsburgh - New York
    {SaintLouis, Pittsburgh, 5},     // 61 - Saint Louis - Pittsburgh
    {Nashville, Pittsburgh, 4},      // 62 - Nashville - Pittsburgh
    {Raleigh, Pittsburgh, 2},        // 63 - Raleigh - Pittsburgh
    {Washington, Pittsburgh, 2},     // 64 - Washington - Pittsburgh
    {NewYork, Washington, 2},        // 65 - New York - Washington
    {SaintLouis, Nashville, 2},      // 66 - Saint Louis - Nashville
    {Nashville, Raleigh, 3},         // 67 - Nashville - Raleigh
    {Raleigh, Washington, 2},        // 68 - Raleigh - Washington
    {LittleRock, Nashville, 3},      // 69 - Little Rock - Nashville
    {Nashville, Atlanta, 1},         // 70 - Nashville - Atlanta
    {Atlanta, Raleigh, 2},           // 71 - Atlanta - Raleigh
    {Raleigh, Charleston, 2},        // 72 - Raleigh - Charleston
    {NewOrleans, Atlanta, 4},        // 73 - New Orleans - Atlanta
    {Atlanta, Miami, 5},             // 74 - Atlanta - Miami
    {Miami, Charleston, 4},          // 75 - Miami - Charleston
    {Miami, NewOrleans, 6},          // 76 - Miami - New Orleans
    {Atlanta, Charleston, 2}         // 77 - Atlanta - Charleston
};

#endif