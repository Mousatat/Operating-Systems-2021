#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *file;
	FILE *fp;
	struct input_event event;
	int state = 0;
	short P_PRESSED = 0, E_PRESSED = 0, A_PRESSED = 0, C_PRESSED = 0, PLUS_PRESSED = 0;

	fp = fopen("./ex3.txt", "w+");
	file = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	if (file != NULL) {
		printf("Try to press shortcuts:\nP + E, C + A + P, C + '+'(Plus button)\n");
		fprintf(fp, "Try to press shortcuts:\nP + E, C + A + P, C + '+'(Plus button)\n");
		fflush(fp);
		while(1) {
			fread(&event, sizeof(struct input_event), 1, file);
			if (event.type == EV_KEY) {
				if (event.value == 0) {
					switch (event.code) {
						case KEY_A: A_PRESSED = 0;break;
						case KEY_C: C_PRESSED = 0;break;
						case KEY_E: E_PRESSED = 0;break;
						case KEY_P: P_PRESSED = 0;break;
						case KEY_KPPLUS: PLUS_PRESSED = 0;break;
					}
				}
				else if (event.value == 1) {
					switch (event.code) {
						case KEY_A: A_PRESSED = 1;break;
						case KEY_C: C_PRESSED = 1;break;
						case KEY_E: E_PRESSED = 1;break;
						case KEY_P: P_PRESSED = 1;break;
						case KEY_KPPLUS: PLUS_PRESSED = 1;break;
					}
				}
				if (P_PRESSED && E_PRESSED) {
					printf("passed!\n");
					fputs("passed!\n", fp);
				}
				if (A_PRESSED && C_PRESSED && P_PRESSED) {
					printf("coco!\n");
					fputs("coco!\n", fp);
				}
				if (C_PRESSED && PLUS_PRESSED) {
					printf("Well done\n");
					fputs("well done\n", fp);
				}
				fflush(fp);
			}
		}
		fclose(file);
		fclose(fp);
	}
}
