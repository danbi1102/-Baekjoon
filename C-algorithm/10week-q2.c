#include <stdio.h>
#define SIZE 5

enum shape_type { //도형의 종류
	TRIANGLE, RECTANGLE, CIRCLE };

struct shape { //도형 타입에 따른 구조체 선언. 도형의 종류에 따른 필요한 입력 변수 선언
	int type;
	union {
		struct {
			double base, height;
		} tri;
		struct {
			double width, height;
		} rect;
		struct {
			double radius;
		} circ;
	} p;
};

void get_shape_data(struct shape s[], int n); //도형 데이터 입력받는 함수
void print_shape_data(struct shape s[], int n); //도형 데이터 출력하는 함수

int main() {
	struct shape s[SIZE];

	printf("### Enter the shape data ###\n");
	get_shape_data(s,SIZE);//함수 호출하여 도형 데이터를 입력받음
	
	printf("### Print the shape data ###\n");
	print_shape_data(s, SIZE); //함수 호출하여 사용자가 원하는 도형 데이터를 출력
}
	
void get_shape_data(struct shape s[], int n) { //배열 s는 도형 데이터 저장할 구조체 배열, n은 입력받을 도형 수
	for (int i = 0; i < n; i++) {
		//도형 타입을 입력받음. 
		printf("도형의 타입을 입력하시오(0-TRIANGLE, 1-RECTANGLE, 2-CIRCLE): ");
		scanf("%d", &s[i].type);

			switch (s[i].type) {
			case TRIANGLE:
				printf("밑변과 높이를 입력하세요: "); //삼각형 밑변과 높이 입력받음
				scanf("%lf %lf", &s[i].p.tri.base, &s[i].p.tri.height);
				break;
			case RECTANGLE:
				printf("가로와 세로의 길이를 입력하세요: "); //직사각형의 가로, 세로 입력받음.
				scanf("%lf %lf", &s[i].p.rect.width, &s[i].p.rect.height);
				break;
			case CIRCLE:
				printf("반지름을 입력하세요: "); //원의 반지름 입력받음. 
				scanf("%lf", &s[i].p.circ.radius);
				break;
			default:
				printf("잘못된 도형 타입입니다. 다시 입력해주세요.\n"); //잘못된 타입 입력시 오류 메세지
				i--;  //반복 횟수 감소시켜서 다시 새로 입력받게 함. 
				break;
			}
	}
}

void print_shape_data(struct shape s[], int n) {
	int count = 0; //출력할 도형의 개수를 세는 변수
	int select_type; // 출력할 도형의 타입을 입력받는 변수

	printf("출력할 도형의 타입을 입력하시오(0-TRIANGLE, 1-RECTANGLE, 2-CIRCLE): ");
	scanf("%d", &select_type);

	for (int i = 0; i < n; i++) {

		if (s[i].type == select_type) { // 배열 s에 저장된 도형 중 입력된 타입과 일치하는 도형을 찾음
			count++;

			switch (s[i].type) {
			case TRIANGLE:
				printf("%d번째 삼각형 면적은 %lf\n", count, 0.5 * s[i].p.tri.base * s[i].p.tri.height);
				break;
			case RECTANGLE:
				printf("%d번째 직사각형 면적은 %lf\n", count, s[i].p.rect.width * s[i].p.rect.height);
				break;
			case CIRCLE:
				printf("%d번째 원 면적은 %lf\n", count, 3.14 * s[i].p.circ.radius * s[i].p.circ.radius);
				break;
			default:
				printf("출력할 도형이 없습니다.");
				break;

			}
		}
	}
	if (count == 0) printf("출력할 도형이 없습니다.");
}