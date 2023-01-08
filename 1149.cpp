//(��1)RGB �Ÿ�
//��� ���� 3���� ������ �̿����� ��ġ�� �ʰ� ĥ�ϴ� �ּ��� ����� ���ϱ�
//dp

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int RGB[3][2] = {};
int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tempRGB[3];
        cin >> tempRGB[0] >> tempRGB[1] >> tempRGB[2];

        if(i == 0)
        {
            RGB[0][1] = tempRGB[0]; 
            RGB[1][1] = tempRGB[1];
            RGB[2][1] = tempRGB[2];
        }
        else
        {
            RGB[0][1] = min(RGB[1][0], RGB[2][0]) + tempRGB[0];
            RGB[1][1] = min(RGB[0][0], RGB[2][0]) + tempRGB[1];
            RGB[2][1] = min(RGB[0][0], RGB[1][0]) + tempRGB[2];
        }

        RGB[0][0] = RGB[0][1];
        RGB[1][0] = RGB[1][1];
        RGB[2][0] = RGB[2][1]; 
    }

    cout << min(min(RGB[0][1], RGB[1][1]), RGB[2][1]);

}