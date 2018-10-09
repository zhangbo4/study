#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showArray(int* array, int size);

void maoPao(int* array, int size); //冒泡排序

int kuaiPaiOne(int* array, int beginIndex, int endIndex); //快排一趟循环 
void kuaiPai(int* array, int begin, int end);  //快速排序

void chaRu(int* array, int size);  //插入排序

void xiEr(int* array, int size); //希尔排序 

void xuanZe(int* array, int size); //选择排序

void duiOne(int* array, int size, int index);//堆排序一趟
void dui(int* array, int size); //堆排序

void guiBing(int* array, int size); //归并排序

void jiShu(int *array, int size); //桶排序、基数排序

int main() 
{
    int array[] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array1[] = {53, 3, 542, 748, 14, 214, 154, 63, 616};

    //冒泡排序
    //maoPao(array, sizeof(array)/sizeof(array[0]));

    //快排
    //kuaiPai(array, 0, sizeof(array)/sizeof(array[0])-1);

    //直接插入排序
    //chaRu(array, sizeof(array)/sizeof(array[0]));

    //希尔排序
    //xiEr(array, sizeof(array)/sizeof(array[0]));

    //选择排序
    //xuanZe(array, sizeof(array)/sizeof(array[0]));

    //选择排序
    //dui(array, sizeof(array)/sizeof(array[0]));

    //归并排序
    //guiBing(array, sizeof(array)/sizeof(array[0]));

    //桶排序、基数排序
    jiShu(array1, sizeof(array1)/sizeof(array1[0]));

    showArray(array1, sizeof(array1)/sizeof(array1[0]));
    return 0; 
}

//冒泡排序
void maoPao(int* array, int size) 
{
    for (int i=0; i<size; i++) 
    {
        for (int j=1; j<(size-i); j++) 
        {
            if (array[j-1] > array[j]) 
            {   
                int temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
        }
    }
}

//快速排序
void kuaiPai(int* array, int begin, int end) 
{
    if (begin > end) 
    {
        return ;
    }

    int index = kuaiPaiOne(array, begin, end);
    kuaiPai(array, begin, index-1);
    kuaiPai(array, index+1, end);
}

int kuaiPaiOne(int* array, int beginIndex, int endIndex) 
{
    int standardIndex = endIndex;         //标准值下标
    int standardValue = array[endIndex];  //标准值
    while(beginIndex < endIndex) 
    {
        for ( ; beginIndex < endIndex; beginIndex++) 
        {
            if (array[beginIndex] > standardValue) 
            {
                break;
            }
        }

        for ( ; endIndex > beginIndex; endIndex--) 
        {
            if (array[endIndex] < standardValue) 
            {
                break;
            }
        }

        if (endIndex > beginIndex) 
        {
            int temp = array[endIndex];
            array[endIndex] = array[beginIndex];
            array[beginIndex] = temp;
        }
    }

    array[standardIndex] = array[beginIndex];
    array[beginIndex] = standardValue;
    return beginIndex;
}

//插入排序
void chaRu(int* array, int size) 
{
    for (int i=0; i<size; i++) 
    {
        for (int j=i; j>0; j--) 
        {
            if (array[j] < array[j-1]) 
            {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }  
            else 
            {
                break;
            } 
        }
    }
} 

//希尔排序
void xiEr(int* array, int size) 
{
    int groupStep = size/2;
    while( groupStep > 0) 
    {
        for (int i=0; i<size; i+=groupStep) 
        {
            for (int j=i; j>0; j-=groupStep) 
            {
                if (array[j] < array[j-groupStep]) 
                {
                    int temp = array[j];
                    array[j] = array[j-groupStep];
                    array[j-groupStep] = temp;
                }  
                else 
                {
                    break;
                } 
            }
        }
        groupStep /= 2;
    }
}

//选择排序
void xuanZe(int* array, int size) 
{
    for (int i=0; i<size; i++) 
    {
        int minIndex = i;
        for (int j=i; j<size; j++) 
        {
            if (array[j] < array[minIndex]) 
            {
                minIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

//堆排序
void dui(int* array, int size) 
{
    for (int i=size/2-1; i>=0; i--) 
    {
        duiOne(array, size, i);
    }
 
    for (int i=size-1; i>0; i--) 
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        duiOne(array, i, 0);
    }
}

//构建大堆
void duiOne(int* array, int size, int index) 
{
    for (int i=index; (2*i+1)<size; ) 
    {
        int leftIndex = 2*i+1;       //左子树下标
        int rightIndex = 2*i+2;      //右子树下标
        int maxIndex = leftIndex;
        if (rightIndex < size && array[leftIndex] < array[rightIndex]) 
        {
            maxIndex = rightIndex;
        }

        if (array[maxIndex] > array[i]) 
        {
            //交换两个元素
            int temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;
            i = maxIndex;
            continue;
        } 
        break;
    }
}

//归并排序
void guiBing(int* array, int size) 
{
    int step = 1;                                                //归并组的长度
    int *tempArray = (int*)malloc(sizeof(int)*size);         
    int *currentArray = array;                                   //当前数组
    int *prepareArray = tempArray;                               //预备数组
    while(step < size) 
    {
        int beginIndex=0;
        for (; beginIndex<size; beginIndex+=(step*2)) 
        {
            if ( (beginIndex+step) >= size) 
            {
                break;
            }

            int firstIndex =  beginIndex;
            int secondIndex = beginIndex+step;
            int newIndex    = beginIndex;
            while(firstIndex < (beginIndex+step) && secondIndex < (beginIndex+2*step) && secondIndex < size ) 
            {
                if (currentArray[firstIndex] < currentArray[secondIndex]) 
                {
                    prepareArray[newIndex++] = currentArray[firstIndex];
                    firstIndex++;
                }
                else 
                {
                    prepareArray[newIndex++] = currentArray[secondIndex];
                    secondIndex++;
                }
            }

            for (;firstIndex < (beginIndex+step);) 
            {
                prepareArray[newIndex++] = currentArray[firstIndex++];
            } 
            for (;secondIndex < (beginIndex+2*step) && secondIndex < size;) 
            {
                prepareArray[newIndex++] = currentArray[secondIndex++];
            }
        }
        //将数组剩余搬下来
        for (;beginIndex < size; beginIndex++) 
        { 
            prepareArray[beginIndex] = currentArray[beginIndex]; 
        }

        //交换使用和备用数组
        int *temp = currentArray;
        currentArray = prepareArray;
        prepareArray = temp;
        
        //增加归并组的长度
        step*=2;

    }

    memcpy(array, currentArray, size*sizeof(int));
    free(tempArray);
    return ;
}

//桶排序、基数排序
void jiShu(int *array, int size) 
{
    //获取需要基数排序的
    int maxBaseNumber = 1;
    for (int i=0; i<size; i++) 
    {
        int temp = array[i]/maxBaseNumber;
        while(temp > 0) 
        {
            temp /= 10;
            maxBaseNumber *= 10;
        }
    }

    int loopBaseNumber = 1;
    int *tempArray = (int *)malloc(sizeof(int)*size);     
    int *currentArray = array;                                   //当前数组
    int *prepareArray = tempArray;                               //预备数组
    while(loopBaseNumber < maxBaseNumber) 
    {
        int baseIndex[10] = {0};
        for (int i=0; i<size; i++) 
        {
            int index = (currentArray[i]/loopBaseNumber)%10;
            baseIndex[index] += 1;
        }
        
        baseIndex[9] = size - baseIndex[9];
        for (int i=9; i>0; i--) 
        {   
            baseIndex[i-1] = baseIndex[i] - baseIndex[i-1];
        }

        for (int i=0; i<size; i++) 
        {
            int index = (currentArray[i]/loopBaseNumber)%10;
            prepareArray[baseIndex[index]] = currentArray[i];
            baseIndex[index] += 1;
        }

        //交换使用和备用数组
        int *temp = currentArray;
        currentArray = prepareArray;
        prepareArray = temp;

        loopBaseNumber *= 10;
    }

    memcpy(array, currentArray, size*sizeof(int));
    free(tempArray);
    return ;
}

//打印数组
void showArray(int* array, int size) 
{
    for (int i=0; i<size; i++) 
    {
        if (i == 0) 
        {
            printf("%d", array[i]);
        } 
        else
        {
            printf(", %d", array[i]);
        } 
    }
    printf("\n");
}
