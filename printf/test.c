int main() {
	char nul = '\0';
	printf("abc\0de\n");

	printf("\n");
	printf("abc%cde\n", nul);
	
	printf("\n");
}
// \b\b\b12
// \n\b\b\b12
