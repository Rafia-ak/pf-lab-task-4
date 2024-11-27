#include <stdio.h>

struct Rectangle{
	float length;
	float width; 
};

int check(struct Rectangle rectangle){
	if (rectangle.width > 0.0 && rectangle.length > 0.0 && rectangle.width < 20.0 && rectangle.length < 20.0){
		return 1;
	}
	return 0;
}

float perimeter(struct Rectangle rectangle){
	float peri = (2 * rectangle.length) + (2 * rectangle.width);
	return peri;
}

float area(struct Rectangle rectangle){
	float area = rectangle.length * rectangle.width;
	return area;
}

int main(){
	struct Rectangle rectangle;
	
	printf("Enter the length of the rectangle: ");
    scanf("%f", &rectangle.length);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &rectangle.width);
	
	if (check(rectangle)){
		printf("Perimeter: %.2f", perimeter(rectangle));
		printf("\nArea: %.2f", area(rectangle));
	}
	else{
		printf("Invalid length/width. Must be >0.0 and <20.0.");
	}	
}


