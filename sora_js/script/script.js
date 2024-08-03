document.body.style.overflow = 'hidden';

const bgSize = 20000;
const player = document.getElementById('player');
const backgroundGray = document.getElementById('background-gray');
const backgroundRed = document.getElementById('background-red');
const obstaclsContainer = document.getElementById('obstacls');

const obs00 = document.querySelector('.o00');
const obs01 = document.querySelector('.o01');
const obs02 = document.querySelector('.o02');
const obs03 = document.querySelector('.o03');
const obs04 = document.querySelector('.o04');
const obs05 = document.querySelector('.o05');
const obs06 = document.querySelector('.o06');
const obs07 = document.querySelector('.o07');
const obs08 = document.querySelector('.o08');
const obs09 = document.querySelector('.o09');
const obs10 = document.querySelector('.o10');
const obs11 = document.querySelector('.o11');
const obs12 = document.querySelector('.o12');
const obs13 = document.querySelector('.o13');
const obs14 = document.querySelector('.o14');
const obs15 = document.querySelector('.o15');
const obs16 = document.querySelector('.o16');
const obs17 = document.querySelector('.o17');
const obs18 = document.querySelector('.o18');
const obs19 = document.querySelector('.o19');
const obs20 = document.querySelector('.o20');
const obs21 = document.querySelector('.o21');
const obs22 = document.querySelector('.o22');
const obs23 = document.querySelector('.o23');
const obs24 = document.querySelector('.o24');
const obs25 = document.querySelector('.o25');
const obs26 = document.querySelector('.o26');
const obs27 = document.querySelector('.o27');
const obs28 = document.querySelector('.o28');
const obs29 = document.querySelector('.o29');
const obs30 = document.querySelector('.o30');
const obs31 = document.querySelector('.o31');
const obs32 = document.querySelector('.o32');
const obs33 = document.querySelector('.o33');
const obs34 = document.querySelector('.o34');
const obs35 = document.querySelector('.o35');
const obs36 = document.querySelector('.o36');
const obs37 = document.querySelector('.o37');
const obs38 = document.querySelector('.o38');
const obs39 = document.querySelector('.o39');
const obs40 = document.querySelector('.o40');
const obs41 = document.querySelector('.o41');
const obs42 = document.querySelector('.o42');
const obs43 = document.querySelector('.o43');
const obs44 = document.querySelector('.o44');
const obs45 = document.querySelector('.o45');
const obs46 = document.querySelector('.o46');
const obs47 = document.querySelector('.o47');
const obs48 = document.querySelector('.o48');
const obs49 = document.querySelector('.o49');
const obs50 = document.querySelector('.o50');
const obs51 = document.querySelector('.o51');
const obs52 = document.querySelector('.o52');
const obs53 = document.querySelector('.o53');
const obs54 = document.querySelector('.o54');
const obs55 = document.querySelector('.o55');
const obs56 = document.querySelector('.o56');
const obs57 = document.querySelector('.o57');
const obs58 = document.querySelector('.o58');
const obs59 = document.querySelector('.o59');
const obs60 = document.querySelector('.o60');
const obs61 = document.querySelector('.o61');
const obs62 = document.querySelector('.o62');
const obs63 = document.querySelector('.o63');
const obs64 = document.querySelector('.o64');
const obs65 = document.querySelector('.o65');
const obs66 = document.querySelector('.o66');
const obs67 = document.querySelector('.o67');
const obs68 = document.querySelector('.o68');
const obs69 = document.querySelector('.o69');
const obs70 = document.querySelector('.o70');
const obs71 = document.querySelector('.o71');
const obs72 = document.querySelector('.o72');
const obs73 = document.querySelector('.o73');
const obs74 = document.querySelector('.o74');
const obs75 = document.querySelector('.o75');
const obs76 = document.querySelector('.o76');
const obs77 = document.querySelector('.o77');
const obs78 = document.querySelector('.o78');
const obs79 = document.querySelector('.o79');

let bgSpeed = 0;
let background = backgroundGray;

background.style.width = `${bgSize}px`;
background.style.height = `${bgSize}px`;
obstaclsContainer.style.width = `${bgSize}px`;
obstaclsContainer.style.height = `${bgSize}px`;

let pressed = false;
let moveSpeed = 0.1;
const returnSpeed = 0.001;
let posP = [window.innerWidth / 2, window.innerHeight / 2];
let center = [window.innerWidth / 2, window.innerHeight / 2];
let backP = [0, 0];

function rand(min, max) { return Math.random() * (max - min) + min; }

const indicEl = document.getElementById('indicator');
const destEl = document.getElementById('destination');
let	destP = [rand(0, bgSize), rand(0, bgSize)];
destEl.style.top = `${destP[0]}px`;
destEl.style.left = `${destP[1]}px`;
const w = rand(200, 600);
destEl.style.width = `${w}px`;
destEl.style.height = `${w}px`;
destDist = bgSize;

const setObstacls = () => {
	const setObs = (obs) => {
		obs.style.top = `${rand(0, bgSize)}px`;
		obs.style.left = `${rand(0, bgSize)}px`;
		const w = rand(300, 800);
		obs.style.width = `${w}px`;
		obs.style.height = `${w}px`;
	}

	setObs(obs00);
	setObs(obs01);
	setObs(obs02);
	setObs(obs03);
	setObs(obs04);
	setObs(obs05);
	setObs(obs06);
	setObs(obs07);
	setObs(obs08);
	setObs(obs09);
	setObs(obs10);
	setObs(obs11);
	setObs(obs12);
	setObs(obs13);
	setObs(obs14);
	setObs(obs15);
	setObs(obs16);
	setObs(obs17);
	setObs(obs18);
	setObs(obs19);
	setObs(obs20);
	setObs(obs21);
	setObs(obs22);
	setObs(obs23);
	setObs(obs24);
	setObs(obs25);
	setObs(obs26);
	setObs(obs27);
	setObs(obs28);
	setObs(obs29);
	setObs(obs30);
	setObs(obs31);
	setObs(obs32);
	setObs(obs33);
	setObs(obs34);
	setObs(obs35);
	setObs(obs36);
	setObs(obs37);
	setObs(obs38);
	setObs(obs39);
	setObs(obs40);
	setObs(obs41);
	setObs(obs42);
	setObs(obs43);
	setObs(obs44);
	setObs(obs45);
	setObs(obs46);
	setObs(obs47);
	setObs(obs48);
	setObs(obs49);
	setObs(obs50);
	setObs(obs51);
	setObs(obs52);
	setObs(obs53);
	setObs(obs54);
	setObs(obs55);
	setObs(obs56);
	setObs(obs57);
	setObs(obs58);
	setObs(obs59);
	setObs(obs60);
	setObs(obs61);
	setObs(obs62);
	setObs(obs63);
	setObs(obs64);
	setObs(obs65);
	setObs(obs66);
	setObs(obs67);
	setObs(obs68);
	setObs(obs69);
	setObs(obs70);
	setObs(obs71);
	setObs(obs72);
	setObs(obs73);
	setObs(obs74);
	setObs(obs75);
	setObs(obs76);
	setObs(obs77);
	setObs(obs78);
	setObs(obs79);
}

setObstacls();

const updatePosition = (x, y) => {
	player.style.left = `${x}px`;
    player.style.top = `${y}px`;
};

const updateRotation = (mouseX, mouseY) => {
	const deltaX = mouseX - posP[0];
    const deltaY = mouseY - posP[1];
    const angle = Math.atan2(deltaY, deltaX) * (180 / Math.PI) + 90;
    player.style.transform = `rotate(${angle}deg)`;
};

const mouseMove = (event) => {
	
	if (!pressed) return;
	let x = event.clientX;
	let y = event.clientY;
	if (event.clientX < window.innerWidth * 0.1)
		x = window.innerWidth * 0.1;
	else if (event.clientX > window.innerWidth - window.innerWidth * 0.1)
		x = window.innerWidth - window.innerWidth * 0.1;
	if (event.clientY < window.innerHeight * 0.1)
		y = window.innerHeight * 0.1;
	else if (event.clientY > window.innerHeight - window.innerHeight * 0.1)
		y = window.innerHeight - window.innerHeight * 0.1;
	const deltaX = x - posP[0];
    const deltaY = y - posP[1];
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
	
	bgSpeed = Math.sqrt(deltaX ** 2 + deltaY ** 2) / Math.max(window.innerWidth, window.innerHeight);
	
    backP[0] -= deltaX * bgSpeed * moveSpeed;
    backP[1] -= deltaY * bgSpeed * moveSpeed;
	
	background.style.left = `${backP[0]}px`;
	obstaclsContainer.style.left = `${backP[0]}px`;
	background.style.top = `${backP[1]}px`;
	obstaclsContainer.style.top = `${backP[1]}px`;
}

const update = () => {
	updateBackground();

	const dx = backP[0] + posP[0];
	const dy = backP[1] + posP[1];
	console.log(dx, dy);
	
	frac = Math.sqrt(dx * dx + dy * dy) / bgSize;
	function interpolateColor(color1, color2, t) {
		const rgb1 = color1.match(/\d+/g).map(Number);
		const rgb2 = color2.match(/\d+/g).map(Number);
	
		const r = Math.round(rgb1[0] + t * (rgb2[0] - rgb1[0]));
		const g = Math.round(rgb1[1] + t * (rgb2[1] - rgb1[1]));
		const b = Math.round(rgb1[2] + t * (rgb2[2] - rgb1[2]));
	
		return `rgb(${r}, ${g}, ${b})`;
	}
	const start = 'rgb(255, 255, 255)';
	const end = 'rgb(241, 14, 58)';
	indicEl.style.fill = interpolateColor(start, end, frac);

	function isOverlapping(element1, element2) {
		const rect1 = element1.getBoundingClientRect();
		const rect2 = element2.getBoundingClientRect();
		
		return !(rect1.right < rect2.left ||
			rect1.left > rect2.right ||
			rect1.bottom < rect2.top ||
			rect1.top > rect2.bottom);
	}

	if (isOverlapping(player, obs00) ||
		isOverlapping(player, obs01) ||
		isOverlapping(player, obs02) ||
		isOverlapping(player, obs03) ||
		isOverlapping(player, obs04) ||
		isOverlapping(player, obs05) ||
		isOverlapping(player, obs06) ||
		isOverlapping(player, obs07) ||
		isOverlapping(player, obs08) ||
		isOverlapping(player, obs09) ||
		isOverlapping(player, obs10) ||
		isOverlapping(player, obs11) ||
		isOverlapping(player, obs12) ||
		isOverlapping(player, obs13) ||
		isOverlapping(player, obs14) ||
		isOverlapping(player, obs15) ||
		isOverlapping(player, obs16) ||
		isOverlapping(player, obs17) ||
		isOverlapping(player, obs18) ||
		isOverlapping(player, obs19) ||
		isOverlapping(player, obs20) ||
		isOverlapping(player, obs21) ||
		isOverlapping(player, obs22) ||
		isOverlapping(player, obs23) ||
		isOverlapping(player, obs24) ||
		isOverlapping(player, obs25) ||
		isOverlapping(player, obs26) ||
		isOverlapping(player, obs27) ||
		isOverlapping(player, obs28) ||
		isOverlapping(player, obs29) ||
		isOverlapping(player, obs30) ||
		isOverlapping(player, obs31) ||
		isOverlapping(player, obs32) ||
		isOverlapping(player, obs33) ||
		isOverlapping(player, obs34) ||
		isOverlapping(player, obs35) ||
		isOverlapping(player, obs36) ||
		isOverlapping(player, obs37) ||
		isOverlapping(player, obs38) ||
		isOverlapping(player, obs39) ||
		isOverlapping(player, obs40) ||
		isOverlapping(player, obs41) ||
		isOverlapping(player, obs42) ||
		isOverlapping(player, obs43) ||
		isOverlapping(player, obs44) ||
		isOverlapping(player, obs45) ||
		isOverlapping(player, obs46) ||
		isOverlapping(player, obs47) ||
		isOverlapping(player, obs48) ||
		isOverlapping(player, obs49) ||
		isOverlapping(player, obs50) ||
		isOverlapping(player, obs51) ||
		isOverlapping(player, obs52) ||
		isOverlapping(player, obs53) ||
		isOverlapping(player, obs54) ||
		isOverlapping(player, obs55) ||
		isOverlapping(player, obs56) ||
		isOverlapping(player, obs57) ||
		isOverlapping(player, obs58) ||
		isOverlapping(player, obs59) ||
		isOverlapping(player, obs60) ||
		isOverlapping(player, obs61) ||
		isOverlapping(player, obs62) ||
		isOverlapping(player, obs63) ||
		isOverlapping(player, obs64) ||
		isOverlapping(player, obs65) ||
		isOverlapping(player, obs66) ||
		isOverlapping(player, obs67) ||
		isOverlapping(player, obs68) ||
		isOverlapping(player, obs79) ||
		isOverlapping(player, obs70) ||
		isOverlapping(player, obs71) ||
		isOverlapping(player, obs72) ||
		isOverlapping(player, obs73) ||
		isOverlapping(player, obs74) ||
		isOverlapping(player, obs75) ||
		isOverlapping(player, obs76) ||
		isOverlapping(player, obs77) ||
		isOverlapping(player, obs78) ||
		isOverlapping(player, obs79)) {
			moveSpeed = 0.005;
		} else {
			moveSpeed = 0.1;
		}
		if (isOverlapping(player, destEl)) {
			moveSpeed = 0.005;
			// background.src = `assets/redC.png`;
		}
		if (!pressed) { returnToCenter(); }
		requestAnimationFrame(update);
	};
	
	document.addEventListener('mousedown', () => {
		pressed = true;
});
document.addEventListener('mouseup', () => {
	pressed = false;
});
document.addEventListener('mousemove', (event) => {
	if (pressed) { mouseMove(event); }
});

requestAnimationFrame(update);
