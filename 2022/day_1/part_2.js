const fs = require("fs");

const filename = "data/puzzle.txt";

fs.readFile(filename, (err, data) => {
    if (err) throw err;

    const elves = data.toString().split("\n\n");

    const calories = elves
        .map((elf) =>
            elf
                .split("\n")
                .map((s) => +s)
                .reduce((sum, cur) => sum + cur, 0)
        )
        .sort((a, b) => b - a);

    console.log(calories[0] + calories[1] + calories[2]);
});
