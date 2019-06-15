#include <stdio.h>
#include <string.h>
#include <time.h>
#include <thread>
#include "algebra3.h"
#include "output.h"
#include "shader.h"

Shader shader;
int main()
{
    time_t timer_s, timer_f;
    
    char filename[30] = "Input_Suzanne.txt";
    if(!shader.readFile(filename)){
        do{
            printf("Cannot find the file, please input the name of information file\n>>");
            scanf_s("%s",filename);
        }while(!shader.readFile(filename));
    }
    vec3 up_direction(0,1,0);
    timer_s = time(0);
    shader.setScreen(1, up_direction);
    filename[strlen(filename)-4] = '\0';
    strcat_s(filename, ".ppm\0");
    shader.outputPPMformat(filename);
    timer_f = time(0);
    printf("\n\nTotal time: %d seconds.\n\n", timer_f - timer_s);
	system("pause");

    return 0;
}
