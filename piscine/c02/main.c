#include <stdio.h>
#include <string.h>

#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
#include "ex12/ft_print_memory.c"

int main(void)
{
    
    printf("\n----ex00----\n");
    char dest0[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char dest00[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char src0[] = "Jungyeki is babo.";
	printf("%s : copied by ft_strcpy\n", ft_strcpy(dest0, src0));
	printf("%s : copied by strcpy\n", strcpy(dest00, src0));
    printf("%s : 세 개 모두 같으면 답\n", src0);

    printf("\n----ex01----\n");
    char dest1[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char dest11[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char src1[] = "TC making is hard";
    printf("%s : copied by ft_strncpy, n = 9\n", ft_strncpy(dest1, src1, 9));
	printf("%s : copied by strncpy, n = 9\n", strncpy(dest11, src1, 9));
	printf("%s : copied by ft_strncpy, n = 20\n", ft_strncpy(dest1, src1, 20));
	printf("%s : copied by strncpy, n = 20\n", strncpy(dest11, src1, 20));

    printf("\n----ex02----\n");
	char str2[] = "Made by";
	char str22[] = "Jungyeki";
	char str222[] = "";
    printf("%d : 0 나오면 답\n", ft_str_is_alpha(str2));
    printf("%d : 1 나오면 답\n", ft_str_is_alpha(str22));
	printf("%d : 1 나오면 답 : empty\n", ft_str_is_alpha(str222));

    printf("\n----ex03----\n");
    char str3[] = "10 01";
	char str33[] = "2022";
	char str333[] = "";
	printf("%d : 0 나오면 답\n", ft_str_is_numeric(str3));
	printf("%d : 1 나오면 답\n", ft_str_is_numeric(str33));
	printf("%d : 1 나오면 답 : empty\n", ft_str_is_numeric(str333));

    printf("\n----ex04----\n");
	char str4[] = "jungYEki";
	char str44[] = "jungyeki";
	char str444[] = "";
	printf("%d : 0 나오면 답\n", ft_str_is_lowercase(str4));
	printf("%d : 1 나오면 답\n", ft_str_is_lowercase(str44));
	printf("%d : 1 나오면 답 : empty\n", ft_str_is_lowercase(str444));

	printf("\n----ex05----\n");
	char str5[] = "JUNGyeKI";
	char str55[] = "JUNGYEKI";
	char str555[] = "";
	printf("%d : 0 나오면 답\n", ft_str_is_uppercase(str5));
	printf("%d : 1 나오면 답\n", ft_str_is_uppercase(str55));
	printf("%d : 1 나오면 답 : empty\n", ft_str_is_uppercase(str555));

    printf("\n----ex06----\n");
	char str6[] = "	";
	char str66[] = "printable!!";
	char str666[] = "";
	printf("%d : 0 나오면 답\n", ft_str_is_printable(str6));
	printf("%d : 1 나오면 답\n", ft_str_is_printable(str66));
	printf("%d : 1 나오면 답 : empty\n", ft_str_is_printable(str666));

    printf("\n----ex07----\n");
	char str7[] = "strUPcase";
	printf("Before : %s\n", str7);
	printf(" After : %s\n모두 대문자로 바뀌었으면 답\n", ft_strupcase(str7));

    printf("\n----ex08----\n");
	char str8[] = "STRlowCASE";
	printf("Before : %s\n", str8);
	printf(" After : %s\n모두 소문자로 바뀌었으면 답\n", ft_strlowcase(str8));

	printf("\n----ex09----\n");
	char str9[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char str99[] = "juugYEki dRINks a CUP of 'coFFee' !";
	printf("Before : %s\n", str9);
	printf(" After : %s\n    답 : Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un\n", ft_strcapitalize(str9));
	printf("Before : %s\n", str99);
	printf(" After : %s\n    답 : Juugyeki Drinks A Cup Of 'Coffee' !\n", ft_strcapitalize(str99));
	
	printf("\n----ex10----\n");
	char dest10[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char src10[] = "jungyeki needs caffeine.";
	printf("%u                       : 24가 보이고\n", ft_strlcpy(dest10, src10, 25));
	printf("%s : 제가 필요한게 보인다면 정답\n", dest10);

	printf("\n----ex11----\n");
	char str11[] = "Coucou\ntu vas bien ?";
	printf("Coucou\\ntu vas bien ?  : Before\n");
	ft_putstr_non_printable(str11);
	printf(" : After\n");
	printf("Coucou\\0atu vas bien ?   이고\n");

	char str1111 = (unsigned char) 255;
	ft_putstr_non_printable(&str1111);
	printf("   이게\n");
	printf("\\ff   같으면 정답 : test extended ascii\n");

	printf("\n----ex12----\n");
	char str12[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n";
	ft_print_memory((void *)str12, sizeof(str12));
	printf("\n");
	
	char str1212[] = "The rest of the small\t\t\t half-moon beach\t\t\t was covered\n\n in a thick layer\t\t\t of broken\t\t\t shells\n\n, a junble\t\t of crustacean parts, and crabs claws.";
	ft_print_memory((void *)str1212, sizeof(str1212));
	printf("\n");

	char str121212[] = "";
	ft_print_memory((void *)str121212, 0);
	printf("< size = 0 인 경우 > : 아무것도 안 나와야 정답\n");

	printf("\n12번은 wocheon님과 chelilee님 께서 도와주셨습니다.\n");

    printf("\nC02 푸시느라 고생하셨습니다.\n\n");
    return(0);
}

