#include<iostream>
#include<math.h>
#include <unistd.h>

using namespace std;
#define pi 3.142
 class donut{
    private:
    float A, B, theta, phi; 
    const float thetaIncrement, phiIncrement, r1, r2, k2;
    char b[1760];
    float z_buf[1760];
    int k1;
    public:
    donut(): thetaIncrement(0.07), phiIncrement(0.02), r2(2), r1(1), k2(5){
        A=0; 
        B=0;
        k1 = 1;

    }
    void createDonut(){
        while(1){
            memset(b, 32, 1760);
            memset(z_buf, 0, 7040);
            for(theta = 0; theta < 2*pi; theta+=thetaIncrement){
                for(phi = 0; phi < 2*pi; phi+=phiIncrement){
                    float sinphi = sin(phi);
                    float cosphi = cos(phi);
                    float sintheta = sin(theta);
                    float costheta = cos(theta);
                    float sinA = sin(A);
                    float sinB = sin(B);
                    float cosA = cos(A);
                    float cosB = cos(B);
                    float xComp = r2 + r1*costheta;
                    float yComp = r1*sintheta;
                    // float d = 1/((sinphi * xComp * cosA) + sintheta*cosA +k2);
                    float d = 1/(sinphi * xComp * sinA + sintheta * cosA + k2);
                    // float t = sinphi * xComp * cosA - sintheta * sinA;
                    int x = 30 + 30*(xComp) * (cosB*cosphi + sinA*sinB*sinphi) - (yComp*cosA*sinB);
                    int y = 15 + 20*(xComp) * (cosphi*sinB + cosB*sinA*sinphi) - (yComp*cosA*cosB);
                    int z =  cosA*xComp*sinphi + yComp*sinA;  
                    //float d = 1/(z+k2);
                    int  xPrime = (k1*x)/(k2*z);
                    int yPrime = (k1*y)/(k2+z);
                    int o = x + 80 * y;
                    int luminance = 8*(cosphi*costheta*sinB - cosA*costheta*sinphi- sinA*sintheta + cosB*(cosA*sinB - costheta*sinA));
                    if (y < 25 && y > 0 && x > 0 && x<100 && d > z_buf[o])
                    {
                        // String D in z-buffer
                        z_buf[o] = d;

                        // Choosing ASCII character based on Luminance and storing it in buffer
                        b[o] = ".,-~:;=!*#$@"[luminance > 0 ? luminance : 0];
                    }



                }
        }
        // cout << "\x1b[H";
        // for (int k = 0; k < 1761; k++)
        // {
        //     cout << (char)(k % 80 ? b[k] : 10);
        //     A += 0.00004;
        //     B += 0.00002;
        // }
        // sleep(100);

        std::cout << "\x1b[H";
        for (k1 = 0; k1 < 1761; k1++)
        {
            putchar(k1 % 80 ? b[k1] : 10);
            A += 0.00004;
            B += 0.00002;
            //usleep(500000);
        }
        usleep(100000);
        }

    }

 };

 int main(){
     donut D;
     D.createDonut();
 }