/*
 * rotary.c
 *
 *  Created on: Jun 27, 2015
 *      Author: Martijn van Dijk
 * 		License: MIT
 */

int position;
int maxPosition;
int minPosition;
int warpAround;

void rotarySetWarpAround(int set) {
	if (set) {
		warpAround = set;
	} else {
		warpAround = 0;
	}
}

int rotaryGetWarpAround(void) {
	return warpAround;
}

int rotaryGetPosition(void) {
	return position;
}

void rotarySetPosition(int pos) {
	position = pos;
}

void rotarySetMin(int min) {
	minPosition = min;
	if (position <= minPosition) {
		position = minPosition;
	}
}

int rotaryGetMin(void) {
	return minPosition;
}

void rotarySetMax(int max) {
	maxPosition = max;
	if (maxPosition != 0) {
		if (position >= maxPosition) {
			position = maxPosition;
		}
	}
}

int rotaryGetMax(void) {
	return maxPosition;
}

void rotaryUpdate(int a, int b) {
	static int previousState[2] = { 0, 0 };

	if (previousState[0] == 1 && previousState[1] == 1) { //11->
		if (a == 1 && b == 0) { //11->10
			position--;
		}
		if (a == 0 && b == 1) { //11->01
			position++;
		}
	}
	if (previousState[0] == 1 && previousState[1] == 0) { //10->
		if (a == 1 && b == 1) { // 10->11
			position++;
		}
		if (a == 0 && b == 0) { //10->00
			position--;
		}
	}
	if (previousState[0] == 0 && previousState[1] == 0) { //00->
		if (a == 1 && b == 0) { //00->10
			position++;
		}
		if (a == 0 && b == 1) { //00->01
			position--;
		}
	}

	previousState[0] = a;
	previousState[1] = b;

	if (position > maxPosition) {
		if (warpAround) {
			position = minPosition;
		} else {
			position = maxPosition;
		}
	}

	if (position < minPosition) {
		if (warpAround) {
			position = maxPosition;
		} else {
			position = minPosition;
		}

	}
}
