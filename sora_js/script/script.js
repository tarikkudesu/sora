document.body.style.overflow = 'hidden';

const player = document.getElementById('player');
const background = document.getElementById('background');

let pressed = false;
const moveSpeed = 0.1;
const returnSpeed = 0.001;
let posP = [window.innerWidth / 2, window.innerHeight / 2];
let center = [window.innerWidth / 2, window.innerHeight / 2];
let backP = [0, 0];

const updatePosition = (x, y) => {
    
    player.style.left = `${x}px`;
    player.style.top = `${y}px`;

};

const updateRotation = (mouseX, mouseY) => {
    const deltaX = mouseX - posP[0];
    const deltaY = mouseY - posP[1];
    const angle = Math.atan2(deltaY, deltaX) * (180 / Math.PI) + 90; // Convert radians to degrees

    player.style.transform = `rotate(${angle}deg)`;
};

const mouseMove = (event) => {

    if (!pressed) return;

    const deltaX = event.clientX - posP[0];
    const deltaY = event.clientY - posP[1];
    const newX = posP[0] + deltaX * moveSpeed;
    const newY = posP[1] + deltaY * moveSpeed;

    updatePosition(newX, newY);

    posP = [newX, newY];

    updateRotation(event.clientX, event.clientY);
};

const returnToCenter = () => {
    if (pressed) return;

    const deltaX = posP[0] - center[0];
    const deltaY = posP[1] - center[1];
    const distance = Math.sqrt(deltaX ** 2 + deltaY ** 2);

    if (distance < 1) return;

    const newX = posP[0] - deltaX * returnSpeed;
    const newY = posP[1] - deltaY * returnSpeed;

    updatePosition(newX, newY);

    posP = [newX, newY];

    requestAnimationFrame(returnToCenter);
};

const   updateBackground = () => {

    const deltaX = posP[0] - center[0];
    const deltaY = posP[1] - center[1];

    backP[0] -= deltaX * moveSpeed;
    backP[1] -= deltaY * moveSpeed;

    backP[0] = backP[0];
    backP[1] = backP[1];
    if (backP[0] > 0)
        backP[0] -= 10000 - center[0] * 2;
    if (backP[1] > 0)
        backP[1] -= 10000 - center[1] * 2;
    if (backP[0] < -10000)
        backP[0] += 10000;
    if (backP[1] < -10000)
        backP[1] += 10000;
    console.log(backP[0], ` `, backP[1]);

    background.style.left = `${backP[0]}px`;
    background.style.top = `${backP[1]}px`;
}

const update = () => {
    updateBackground();
    if (!pressed) { returnToCenter(); }
    requestAnimationFrame(update);
};

const   mousePress = (event) => {
    pressed = true;
}
const   mouseRelease = (event) => {
    pressed = false;
}

document.addEventListener('mousedown', mousePress);
document.addEventListener('mouseup', mouseRelease);
document.addEventListener('mousemove', (event) => {
    if (pressed) { mouseMove(event); }
});

requestAnimationFrame(update);