// Example game:
//   int player0connections[] = {0, 12, 26, 77, 50, 51, 74, 76, 71, 59, 48, 33, 24, 9, 63};
//   int player1connections[] = {73, 56, 55, 54, 29, 15, 14, 13, 1, 10, 23, 22, 21, 5, 4};
//   int player2connections[] = {14, 15, 16, 11, 27, 31, 49, 33, 60, 61, 71, 47, 46, 45, 37, 21, 40};

enum City
{
    VANCOUVER,
    CALGARY,
    WINNIPEG,
    SAULT_ST_MARIE,
    MONTREAL,
    BOSTON,
    TORONTO,
    DULUTH,
    HELENA,
    SEATTLE,
    PORTLAND,
    SAN_FRANCISCO,
    SALT_LAKE_CITY,
    DENVER,
    OMAHA,
    CHICAGO,
    PITTSBURGH,
    NEW_YORK,
    WASHINGTON,
    RALEIGH,
    NASHVILLE,
    ST_LOUIS,
    KANSAS_CITY,
    LAS_VEGAS,
    SANTA_FE,
    OKLAHOMA_CITY,
    LITTLE_ROCK,
    ATLANTA,
    CHARLESTON,
    LOS_ANGELES,
    PHOENIX,
    EL_PASO,
    DALLAS,
    HOUSTON,
    NEW_ORLEANS,
    MIAMI,

    NUM_CITIES
};

// Define a structure to represent a route
struct Route
{
    City from;
    City to;
    int distance;
};

// List of routes and distances
const std::vector<Route> routes = {
    {VANCOUVER, CALGARY, 3},            // 0
    {CALGARY, WINNIPEG, 6},             // 1
    {WINNIPEG, SAULT_ST_MARIE, 6},      // 2
    {SAULT_ST_MARIE, MONTREAL, 5},      // 3
    {MONTREAL, BOSTON, 2},              // 4
    {BOSTON, NEW_YORK, 2},              // 5
    {NEW_YORK, MONTREAL, 3},            // 6
    {MONTREAL, TORONTO, 3},             // 7
    {TORONTO, SAULT_ST_MARIE, 2},       // 8
    {SAULT_ST_MARIE, DULUTH, 3},        // 9
    {DULUTH, WINNIPEG, 4},              // 10
    {WINNIPEG, HELENA, 4},              // 11
    {HELENA, CALGARY, 4},               // 12
    {CALGARY, SEATTLE, 4},              // 13
    {SEATTLE, VANCOUVER, 1},            // 14
    {SEATTLE, PORTLAND, 1},             // 15
    {SEATTLE, HELENA, 6},               // 16
    {HELENA, DULUTH, 6},                // 17
    {DULUTH, TORONTO, 6},               // 18
    {CHICAGO, TORONTO, 4},              // 19
    {TORONTO, PITTSBURGH, 2},           // 20
    {PITTSBURGH, NEW_YORK, 2},          // 21
    {PITTSBURGH, CHICAGO, 3},           // 22
    {CHICAGO, DULUTH, 3},               // 23
    {DULUTH, OMAHA, 2},                 // 24
    {OMAHA, HELENA, 5},                 // 25
    {HELENA, DENVER, 4},                // 26
    {HELENA, SALT_LAKE_CITY, 3},        // 27
    {PORTLAND, SALT_LAKE_CITY, 6},      // 28
    {PORTLAND, SAN_FRANCISCO, 5},       // 29
    {SAN_FRANCISCO, SALT_LAKE_CITY, 5}, // 30
    {SALT_LAKE_CITY, DENVER, 3},        // 31
    {DENVER, OMAHA, 4},                 // 32
    {OMAHA, KANSAS_CITY, 1},            // 33
    {OMAHA, CHICAGO, 4},                // 34
    {KANSAS_CITY, ST_LOUIS, 2},         // 35
    {ST_LOUIS, CHICAGO, 2},             // 36
    {ST_LOUIS, PITTSBURGH, 5},          // 37
    {NASHVILLE, PITTSBURGH, 4},         // 38
    {RALEIGH, PITTSBURGH, 2},           // 39
    {PITTSBURGH, WASHINGTON, 2},        // 40
    {NEW_YORK, WASHINGTON, 2},          // 41
    {WASHINGTON, RALEIGH, 2},           // 42
    {RALEIGH, CHARLESTON, 2},           // 43
    {RALEIGH, ATLANTA, 2},              // 44
    {RALEIGH, NASHVILLE, 3},            // 45
    {NASHVILLE, ST_LOUIS, 2},           // 46
    {ST_LOUIS, LITTLE_ROCK, 2},         // 47
    {KANSAS_CITY, OKLAHOMA_CITY, 4},    // 48
    {OKLAHOMA_CITY, DENVER, 4},         // 49
    {DENVER, SANTA_FE, 2},              // 50
    {DENVER, PHOENIX, 5},               // 51
    {SALT_LAKE_CITY, LAS_VEGAS, 3},     // 52
    {LAS_VEGAS, LOS_ANGELES, 2},        // 53
    {LOS_ANGELES, SAN_FRANCISCO, 3},    // 54
    {LOS_ANGELES, PHOENIX, 3},          // 55
    {PHOENIX, SANTA_FE, 3},             // 56
    {SANTA_FE, OKLAHOMA_CITY, 3},       // 57
    {EL_PASO, OKLAHOMA_CITY, 5},        // 58
    {DALLAS, OKLAHOMA_CITY, 2},         // 59
    {OKLAHOMA_CITY, LITTLE_ROCK, 2},    // 60
    {LITTLE_ROCK, DALLAS, 2},           // 61
    {LITTLE_ROCK, NEW_ORLEANS, 3},      // 62
    {LITTLE_ROCK, NASHVILLE, 3},        // 63
    {NASHVILLE, ATLANTA, 1},            // 64
    {ATLANTA, NEW_ORLEANS, 4},          // 65
    {ATLANTA, MIAMI, 5},                // 66
    {ATLANTA, CHARLESTON, 2},           // 67
    {CHARLESTON, MIAMI, 4},             // 68
    {MIAMI, NEW_ORLEANS, 6},            // 69
    {NEW_ORLEANS, HOUSTON, 2},          // 70
    {HOUSTON, DALLAS, 1},               // 71
    {DALLAS, EL_PASO, 4},               // 72
    {EL_PASO, SANTA_FE, 2},             // 73
    {EL_PASO, PHOENIX, 3},              // 74
    {EL_PASO, LOS_ANGELES, 6},          // 75
    {EL_PASO, HOUSTON, 6},              // 76
    {DENVER, KANSAS_CITY, 4}            // 77
};

const std::string CityNames[] = {
    "Vancouver",
    "Calgary",
    "Winnipeg",
    "Sault St. Marie",
    "Montreal",
    "Boston",
    "Toronto",
    "Duluth",
    "Helena",
    "Seattle",
    "Portland",
    "San Francisco",
    "Salt Lake City",
    "Denver",
    "Omaha",
    "Chicago",
    "Pittsburgh",
    "New York",
    "Washington",
    "Raleigh",
    "Nashville",
    "St Louis",
    "Kansas City",
    "Las Vegas",
    "Santa Fe",
    "Oklahoma City",
    "Little Rock",
    "Atlanta",
    "Charleston",
    "Los Angeles",
    "Phoenix",
    "El Paso",
    "Dallas",
    "Houston",
    "New Orleans",
    "Miami"};

// unsigned int routeAndDistance[][3] = {
//     {VANCOUVER, CALGARY, 3},            // 0
//     {CALGARY, WINNIPEG, 6},             // 1
//     {WINNIPEG, SAULT_ST_MARIE, 6},      // 2
//     {SAULT_ST_MARIE, MONTREAL, 5},      // 3
//     {MONTREAL, BOSTON, 2},              // 4
//     {BOSTON, NEW_YORK, 2},              // 5
//     {NEW_YORK, MONTREAL, 3},            // 6
//     {MONTREAL, TORONTO, 3},             // 7
//     {TORONTO, SAULT_ST_MARIE, 2},       // 8
//     {SAULT_ST_MARIE, DULUTH, 3},        // 9
//     {DULUTH, WINNIPEG, 4},              // 10
//     {WINNIPEG, HELENA, 4},              // 11
//     {HELENA, CALGARY, 4},               // 12
//     {CALGARY, SEATTLE, 4},              // 13
//     {SEATTLE, VANCOUVER, 1},            // 14
//     {SEATTLE, PORTLAND, 1},             // 15
//     {SEATTLE, HELENA, 6},               // 16
//     {HELENA, DULUTH, 6},                // 17
//     {DULUTH, TORONTO, 6},               // 18
//     {CHICAGO, TORONTO, 4},              // 19
//     {TORONTO, PITTSBURGH, 2},           // 20
//     {PITTSBURGH, NEW_YORK, 2},          // 21
//     {PITTSBURGH, CHICAGO, 3},           // 22
//     {CHICAGO, DULUTH, 3},               // 23
//     {DULUTH, OMAHA, 2},                 // 24
//     {OMAHA, HELENA, 5},                 // 25
//     {HELENA, DENVER, 4},                // 26
//     {HELENA, SALT_LAKE_CITY, 3},        // 27
//     {PORTLAND, SALT_LAKE_CITY, 6},      // 28
//     {PORTLAND, SAN_FRANCISCO, 5},       // 29
//     {SAN_FRANCISCO, SALT_LAKE_CITY, 5}, // 30
//     {SALT_LAKE_CITY, DENVER, 3},        // 31
//     {DENVER, OMAHA, 4},                 // 32
//     {OMAHA, KANSAS_CITY, 1},            // 33
//     {OMAHA, CHICAGO, 4},                // 34
//     {KANSAS_CITY, ST_LOUIS, 2},         // 35
//     {ST_LOUIS, CHICAGO, 2},             // 36
//     {ST_LOUIS, PITTSBURGH, 5},          // 37
//     {NASHVILLE, PITTSBURGH, 4},         // 38
//     {RALEIGH, PITTSBURGH, 2},           // 39
//     {PITTSBURGH, WASHINGTON, 2},        // 40
//     {NEW_YORK, WASHINGTON, 2},          // 41
//     {WASHINGTON, RALEIGH, 2},           // 42
//     {RALEIGH, CHARLESTON, 2},           // 43
//     {RALEIGH, ATLANTA, 2},              // 44
//     {RALEIGH, NASHVILLE, 3},            // 45
//     {NASHVILLE, ST_LOUIS, 2},           // 46
//     {ST_LOUIS, LITTLE_ROCK, 2},         // 47
//     {KANSAS_CITY, OKLAHOMA_CITY, 4},    // 48
//     {OKLAHOMA_CITY, DENVER, 4},         // 49
//     {DENVER, SANTA_FE, 2},              // 50
//     {DENVER, PHOENIX, 5},               // 51
//     {SALT_LAKE_CITY, LAS_VEGAS, 3},     // 52
//     {LAS_VEGAS, LOS_ANGELES, 2},        // 53
//     {LOS_ANGELES, SAN_FRANCISCO, 3},    // 54
//     {LOS_ANGELES, PHOENIX, 3},          // 55
//     {PHOENIX, SANTA_FE, 3},             // 56
//     {SANTA_FE, OKLAHOMA_CITY, 3},       // 57
//     {EL_PASO, OKLAHOMA_CITY, 5},        // 58
//     {DALLAS, OKLAHOMA_CITY, 2},         // 59
//     {OKLAHOMA_CITY, LITTLE_ROCK, 2},    // 60
//     {LITTLE_ROCK, DALLAS, 2},           // 61
//     {LITTLE_ROCK, NEW_ORLEANS, 3},      // 62
//     {LITTLE_ROCK, NASHVILLE, 3},        // 63
//     {NASHVILLE, ATLANTA, 1},            // 64
//     {ATLANTA, NEW_ORLEANS, 4},          // 65
//     {ATLANTA, MIAMI, 5},                // 66
//     {ATLANTA, CHARLESTON, 2},           // 67
//     {CHARLESTON, MIAMI, 4},             // 68
//     {MIAMI, NEW_ORLEANS, 6},            // 69
//     {NEW_ORLEANS, HOUSTON, 2},          // 70
//     {HOUSTON, DALLAS, 1},               // 71
//     {DALLAS, EL_PASO, 4},               // 72
//     {EL_PASO, SANTA_FE, 2},             // 73
//     {EL_PASO, PHOENIX, 3},              // 74
//     {PHOENIX, LOS_ANGELES, 6},          // 75
//     {LOS_ANGELES, EL_PASO, 6},          // 76
//     {DENVER, KANSAS_CITY, 4}            // 77
// };

// std::unordered_map<CityID, std::unordered_map<CityID, int>> graph = {
//     {VANCOUVER, {{CALGARY, 3}, {SEATTLE, 1}}},
//     {CALGARY, {{VANCOUVER, 3}, {WINNIPEG, 6}, {HELENA, 4}, {SEATTLE, 4}}},
//     {WINNIPEG, {{CALGARY, 6}, {SAULT_ST_MARIE, 6}, {DULUTH, 4}, {HELENA, 4}}},
//     {SAULT_ST_MARIE, {{WINNIPEG, 6}, {MONTREAL, 5}, {TORONTO, 2}, {DULUTH, 3}}},
//     {MONTREAL, {{SAULT_ST_MARIE, 5}, {BOSTON, 2}, {NEW_YORK, 3}, {TORONTO, 3}}},
//     {BOSTON, {{MONTREAL, 2}, {NEW_YORK, 2}}},
//     {TORONTO, {{SAULT_ST_MARIE, 2}, {MONTREAL, 3}, {PITTSBURGH, 2}, {CHICAGO, 4}}},
//     {DULUTH, {{WINNIPEG, 4}, {SAULT_ST_MARIE, 3}, {CHICAGO, 3}, {OMAHA, 2}, {HELENA, 6}}},
//     {HELENA, {{CALGARY, 4}, {WINNIPEG, 4}, {DULUTH, 6}, {OMAHA, 5}, {DENVER, 4}, {SALT_LAKE_CITY, 3}, {SEATTLE, 6}}},
//     {SEATTLE, {{VANCOUVER, 1}, {CALGARY, 4}, {HELENA, 6}, {PORTLAND, 1}}},
//     {PORTLAND, {{SEATTLE, 1}, {SALT_LAKE_CITY, 6}, {SAN_FRANCISCO, 5}}},
//     {SAN_FRANCISCO, {{PORTLAND, 5}, {SALT_LAKE_CITY, 5}, {LOS_ANGELES, 3}}},
//     {SALT_LAKE_CITY, {{HELENA, 3}, {DENVER, 3}, {OMAHA, 4}, {KANSAS_CITY, 4}, {LAS_VEGAS, 3}, {SAN_FRANCISCO, 5}, {PORTLAND, 6}}},
//     {DENVER, {{HELENA, 4}, {OMAHA, 4}, {KANSAS_CITY, 4}, {OKLAHOMA_CITY, 4}, {SANTA_FE, 2}, {PHOENIX, 5}, {SALT_LAKE_CITY, 3}}},
//     {OMAHA, {{DULUTH, 2}, {HELENA, 5}, {DENVER, 4}, {KANSAS_CITY, 1}, {CHICAGO, 4}}},
//     {CHICAGO, {{DULUTH, 3}, {TORONTO, 4}, {PITTSBURGH, 3}, {ST_LOUIS, 2}, {OMAHA, 4}}},
//     {PITTSBURGH, {{CHICAGO, 3}, {TORONTO, 2}, {NEW_YORK, 2}, {WASHINGTON, 2}, {RALEIGH, 2}, {NASHVILLE, 4}, {ST_LOUIS, 5}}},
//     {NEW_YORK, {{MONTREAL, 3}, {BOSTON, 2}, {PITTSBURGH, 2}, {WASHINGTON, 2}}},
//     {WASHINGTON, {{NEW_YORK, 2}, {PITTSBURGH, 2}, {RALEIGH, 2}}},
//     {RALEIGH, {{WASHINGTON, 2}, {PITTSBURGH, 2}, {NASHVILLE, 3}, {CHARLESTON, 2}, {ATLANTA, 2}}},
//     {NASHVILLE, {{PITTSBURGH, 4}, {RALEIGH, 3}, {ATLANTA, 1}, {ST_LOUIS, 2}, {LITTLE_ROCK, 3}}},
//     {ST_LOUIS, {{CHICAGO, 2}, {PITTSBURGH, 5}, {NASHVILLE, 2}, {LITTLE_ROCK, 2}, {KANSAS_CITY, 2}}},
//     {KANSAS_CITY, {{ST_LOUIS, 2}, {OMAHA, 1}, {DENVER, 4}, {OKLAHOMA_CITY, 4}}},
//     {LAS_VEGAS, {{SALT_LAKE_CITY, 3}, {LOS_ANGELES, 2}}},
//     {SANTA_FE, {{DENVER, 2}, {PHOENIX, 3}, {EL_PASO, 2}}},
//     {OKLAHOMA_CITY, {{DENVER, 4}, {KANSAS_CITY, 4}, {OMAHA, 4}, {DALLAS, 2}, {EL_PASO, 5}, {LITTLE_ROCK, 2}}},
//     {LITTLE_ROCK, {{NASHVILLE, 3}, {ST_LOUIS, 2}, {KANSAS_CITY, 2}, {OKLAHOMA_CITY, 2}, {DALLAS, 2}, {NEW_ORLEANS, 3}}},
//     {ATLANTA, {{RALEIGH, 2}, {NASHVILLE, 1}, {CHARLESTON, 2}, {MIAMI, 5}, {NEW_ORLEANS, 4}}},
//     {CHARLESTON, {{RALEIGH, 2}, {ATLANTA, 2}, {MIAMI, 4}}},
//     {LOS_ANGELES, {{SAN_FRANCISCO, 3}, {LAS_VEGAS, 2}, {PHOENIX, 3}, {EL_PASO, 6}}},
//     {PHOENIX, {{LOS_ANGELES, 3}, {SANTA_FE, 3}, {DENVER, 5}, {EL_PASO, 3}, {LOS_ANGELES, 3}}},
//     {EL_PASO, {{PHOENIX, 3}, {SANTA_FE, 2}, {OKLAHOMA_CITY, 5}, {DALLAS, 4}, {HOUSTON, 6}, {LOS_ANGELES, 6}}},
//     {DALLAS, {{OKLAHOMA_CITY, 2}, {LITTLE_ROCK, 2}, {HOUSTON, 1}, {EL_PASO, 4}}},
//     {HOUSTON, {{DALLAS, 1}, {NEW_ORLEANS, 2}, {EL_PASO, 6}}},
//     {NEW_ORLEANS, {{HOUSTON, 2}, {ATLANTA, 4}, {MIAMI, 6}, {LITTLE_ROCK, 3}}},
//     {MIAMI, {{ATLANTA, 5}, {CHARLESTON, 4}, {NEW_ORLEANS, 6}}}};

// const unsigned char routesInGraph[78][2][2] = {
//     {{VANCOUVER, 0}, {CALGARY, 0}},       // 0 - Vancouver - Calgary
//     {{CALGARY, 1}, {WINNIPEG, 0}},        // 1 - Calgary - Winnipeg
//     {{WINNIPEG, 1}, {SAULT_ST_MARIE, 0}}, // 2 - Winnipeg - Sault St. Marie
//     {{SAULT_ST_MARIE, 1}, {MONTREAL, 0}}, // 3 - Sault St. Marie - Montreal
//     {{MONTREAL, 1}, {BOSTON, 0}},         // 4 - Montreal - Boston
//     {{BOSTON, 1}, {NEW_YORK, 0}},         // 5 - Boston - New York
//     {{NEW_YORK, 1}, {MONTREAL, 1}},       // 6 - New York - Montreal
//     {{MONTREAL, 2}, {TORONTO, 0}},        // 7 - Montreal - Toronto
//     {{TORONTO, 1}, {SAULT_ST_MARIE, 2}},  // 8 - Toronto - Sault St. Marie
//     {{SAULT_ST_MARIE, 3}, {DULUTH, 0}},   // 9 - Sault St. Marie - Duluth
//     {{DULUTH, 1}, {WINNIPEG, 2}},         // 10 - Duluth - Winnipeg
//     {{WINNIPEG, 3}, {HELENA, 0}},         // 11 - Winnipeg - Helena
//     {{HELENA, 1}, {CALGARY, 2}},          // 12 - Helena - Calgary
//     {{CALGARY, 3}, {SEATTLE, 0}},         // 13 - Calgary - Seattle
//     {{SEATTLE, 1}, {VANCOUVER, 1}},       // 14 - Seattle - Vancouver
//     {{SEATTLE, 2}, {PORTLAND, 0}},        // 15 - Seattle - Portland
//     {{SEATTLE, 3}, {HELENA, 2}},          // 16 - Seattle - Helena
//     {{HELENA, 3}, {DULUTH, 2}},           // 17 - Helena - Duluth
//     {{DULUTH, 4}, {TORONTO, 2}},          // 18 - Duluth - Toronto
//     {{CHICAGO, 0}, {TORONTO, 3}},         // 19 - Chicago - Toronto
//     {{TORONTO, 4}, {PITTSBURGH, 0}},      // 20 - Toronto - Pittsburgh
//     {{PITTSBURGH, 1}, {NEW_YORK, 2}},     // 21 - Pittsburgh - New York
//     {{PITTSBURGH, 2}, {CHICAGO, 1}},      // 22 - Pittsburgh - Chicago
//     // ...
// };

// const CityID routes[][2] = {
//     {VANCOUVER, CALGARY},            // 0
//     {CALGARY, WINNIPEG},             // 1
//     {WINNIPEG, SAULT_ST_MARIE},      // 2
//     {SAULT_ST_MARIE, MONTREAL},      // 3
//     {MONTREAL, BOSTON},              // 4
//     {BOSTON, NEW_YORK},              // 5
//     {NEW_YORK, MONTREAL},            // 6
//     {MONTREAL, TORONTO},             // 7
//     {TORONTO, SAULT_ST_MARIE},       // 8
//     {SAULT_ST_MARIE, DULUTH},        // 9
//     {DULUTH, WINNIPEG},              // 10
//     {WINNIPEG, HELENA},              // 11
//     {HELENA, CALGARY},               // 12
//     {CALGARY, SEATTLE},              // 13
//     {SEATTLE, VANCOUVER},            // 14
//     {SEATTLE, PORTLAND},             // 15
//     {SEATTLE, HELENA},               // 16
//     {HELENA, DULUTH},                // 17
//     {DULUTH, TORONTO},               // 18
//     {CHICAGO, TORONTO},              // 19
//     {TORONTO, PITTSBURGH},           // 20
//     {PITTSBURGH, NEW_YORK},          // 21
//     {PITTSBURGH, CHICAGO},           // 22
//     {CHICAGO, DULUTH},               // 23
//     {DULUTH, OMAHA},                 // 24
//     {OMAHA, HELENA},                 // 25
//     {HELENA, DENVER},                // 26
//     {HELENA, SALT_LAKE_CITY},        // 27
//     {PORTLAND, SALT_LAKE_CITY},      // 28
//     {PORTLAND, SAN_FRANCISCO},       // 29
//     {SAN_FRANCISCO, SALT_LAKE_CITY}, // 30
//     {SALT_LAKE_CITY, DENVER},        // 31
//     {DENVER, OMAHA},                 // 32
//     {OMAHA, KANSAS_CITY},            // 33
//     {OMAHA, CHICAGO},                // 34
//     {KANSAS_CITY, ST_LOUIS},         // 35
//     {ST_LOUIS, CHICAGO},             // 36
//     {ST_LOUIS, PITTSBURGH},          // 37
//     {NASHVILLE, PITTSBURGH},         // 38
//     {RALEIGH, PITTSBURGH},           // 39
//     {PITTSBURGH, WASHINGTON},        // 40
//     {NEW_YORK, WASHINGTON},          // 41
//     {WASHINGTON, RALEIGH},           // 42
//     {RALEIGH, CHARLESTON},           // 43
//     {RALEIGH, ATLANTA},              // 44
//     {RALEIGH, NASHVILLE},            // 45
//     {NASHVILLE, ST_LOUIS},           // 46
//     {ST_LOUIS, LITTLE_ROCK},         // 47
//     {KANSAS_CITY, OKLAHOMA_CITY},    // 48
//     {OKLAHOMA_CITY, DENVER},         // 49
//     {DENVER, SANTA_FE},              // 50
//     {DENVER, PHOENIX},               // 51
//     {SALT_LAKE_CITY, LAS_VEGAS},     // 52
//     {LAS_VEGAS, LOS_ANGELES},        // 53
//     {LOS_ANGELES, SAN_FRANCISCO},    // 54
//     {LOS_ANGELES, PHOENIX},          // 55
//     {PHOENIX, SANTA_FE},             // 56
//     {SANTA_FE, OKLAHOMA_CITY},       // 57
//     {EL_PASO, OKLAHOMA_CITY},        // 58
//     {DALLAS, OKLAHOMA_CITY},         // 59
//     {OKLAHOMA_CITY, LITTLE_ROCK},    // 60
//     {LITTLE_ROCK, DALLAS},           // 61
//     {LITTLE_ROCK, NEW_ORLEANS},      // 62
//     {LITTLE_ROCK, NASHVILLE},        // 63
//     {NASHVILLE, ATLANTA},            // 64
//     {ATLANTA, NEW_ORLEANS},          // 65
//     {ATLANTA, MIAMI},                // 66
//     {ATLANTA, CHARLESTON},           // 67
//     {CHARLESTON, MIAMI},             // 68
//     {MIAMI, NEW_ORLEANS},            // 69
//     {NEW_ORLEANS, HOUSTON},          // 70
//     {HOUSTON, DALLAS},               // 71
//     {DALLAS, EL_PASO},               // 72
//     {EL_PASO, SANTA_FE},             // 73
//     {EL_PASO, PHOENIX},              // 74
//     {PHOENIX, LOS_ANGELES},          // 75
//     {LOS_ANGELES, EL_PASO},          // 76
//     {DENVER, KANSAS_CITY},           // 77
// };

const unsigned int routeLength[] = {
    3, // 0 - Vancouver - Calgary
    6, // 1 - Calgary - Winnipeg
    6, // 2 - Winnipeg - Sault St. Marie
    5, // 3 - Sault St. Marie - Montreal
    2, // 4 - Montreal - Boston
    2, // 5 - Boston - New York
    3, // 6 - New York - Montreal
    3, // 7 - Montreal - Toronto
    2, // 8 - Toronto - Sault St. Marie
    3, // 9 - Sault St. Marie - Duluth
    4, // 10 - Duluth - Winnipeg
    4, // 11 - Winnipeg - Helena
    4, // 12 - Helena - Calgary
    4, // 13 - Calgary - Seattle
    1, // 14 - Seattle - Vancouver
    1, // 15 - Seattle - Portland
    6, // 16 - Seattle - Helena
    6, // 17 - Helena - Duluth
    6, // 18 - Duluth - Toronto
    4, // 19 - Chicago - Toronto
    2, // 20 - Toronto - Pittsburgh
    2, // 21 - Pittsburgh - New York
    3, // 22 - Pittsburgh - Chicago
    3, // 23 - Chicago - Duluth
    2, // 24 - Duluth - Omaha
    5, // 25 - Omaha - Helena
    4, // 26 - Helena - Denver
    3, // 27 - Helena - Salt Lake City
    6, // 28 - Portland - Salt Lake City
    5, // 29 - Portland - San Francisco
    5, // 30 - San Francisco - Salt Lake City
    3, // 31 - Salt Lake City - Denver
    4, // 32 - Denver - Omaha
    1, // 33 - Omaha - Kansas City
    4, // 34 - Omaha - Chicago
    2, // 35 - Kansas City - St. Louis
    2, // 36 - St. Louis - Chicago
    5, // 37 - St. Louis - Pittsburgh
    4, // 38 - Nashville - Pittsburgh
    2, // 39 - Raleigh - Pittsburgh
    2, // 40 - Pittsburgh - Washington
    2, // 41 - New York - Washington
    2, // 42 - Washington - Raleigh
    2, // 43 - Raleigh - Charleston
    2, // 44 - Raleigh - Atlanta
    3, // 45 - Raleigh - Nashville
    2, // 46 - Nashville - St. Louis
    2, // 47 - St. Louis - Little Rock
    2, // 48 - Kansas City - Oklahoma City
    4, // 49 - Oklahoma City - Denver
    2, // 50 - Denver - Santa Fe
    5, // 51 - Denver - Phoenix
    3, // 52 - Salt Lake City - Las Vegas
    2, // 53 - Las Vegas - Los Angeles
    3, // 54 - Los Angeles - San Francisco
    3, // 55 - Los Angeles - Phoenix
    3, // 56 - Phoenix - Santa Fe
    3, // 57 - Santa Fe - Oklahoma City
    5, // 58 - El Paso - Oklahoma City
    2, // 59 - Dallas - Oklahoma City
    2, // 60 - Oklahoma City - Little Rock
    2, // 61 - Little Rock - Dallas
    3, // 62 - Little Rock - New Orleans
    3, // 63 - Little Rock - Nashville
    1, // 64 - Nashville - Atlanta
    4, // 65 - Atlanta - New Orleans
    5, // 66 - Atlanta - Miami
    2, // 67 - Atlanta - Charleston
    4, // 68 - Charleston - Miami
    6, // 69 - Miami - New Orleans
    2, // 70 - New Orleans - Houston
    1, // 71 - Houston - Dallas
    4, // 72 - Dallas - El Paso
    2, // 73 - El Paso - Santa Fe
    3, // 74 - El Paso - Phoenix
    6, // 75 - Phoenix - Los Angeles
    6, // 76 - Los Angeles - El Paso
    4, // 77 - Denver - Kansas City
};