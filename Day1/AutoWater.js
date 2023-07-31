let currentTime = 0;
let lastChecked = 0;
input.onButtonPressed(Button.A, function () {
    checkIfWatered()
})
function checkIfWatered () {
    if (cakLandSoil.ifMoisture(cakLandSoil.SoilPin.P0, cakLandSoil.Mlevel.DRY) || cakLandSoil.ifMoisture(cakLandSoil.SoilPin.P0, cakLandSoil.Mlevel.VERY_DRY)) {
        basic.showLeds(`
            # . . . #
            . # . # .
            . . # . .
            . # . # .
            # . . . #
            `);
        cakLandPump.startDuration(cakLand.BoardSide.RIGHT, 60, 3);
    } else {
        basic.showLeds(`
            . . # . .
            . # # # .
            # # # # #
            . # # # .
            . . # . .
            `);
        basic.pause(100);
        basic.showLeds(`
            . . # . .
            . # . # .
            # . . . #
            . # . # .
            . . # . .
            `);
        basic.pause(100);
    }
}
basic.forever(function () {
    currentTime = input.runningTime();
    if (currentTime - lastChecked > 10000) {
        lastChecked = currentTime;
        checkIfWatered();
    }
})
