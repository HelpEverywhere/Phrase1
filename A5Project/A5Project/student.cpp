#include "stdafx.h"
// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name
//ERROR_I_have_NOT_yet_completed_the_INTEGRITY_statement
// Name:
// login ID:

// implementation:
  
void initialize_new_student(struct student *s)
{
	s->cs_grade = 0;
	s->cs_num_fail = 0;
	s->cs_num_pass = 0;
	s->non_cs_grade = 0;
	s->non_cs_num_fail = 0;
	s->non_cs_num_pass = 0;
}

void take_course(struct student *s, int grade, bool cs)
{
	if (cs == 1)
	{
		s->cs_grade += grade;
		if (grade<60)
			++s->cs_num_fail;
		else
			++s->cs_num_pass;
	}
	else
	{
		s->non_cs_grade += grade;
		if (grade<60)
			++s->non_cs_num_fail;
		else
			++s->non_cs_num_pass;
	}

}

void adjust_grade(struct student *s, int original_grade,int new_grade, bool cs)
{
	if (cs == 1)
	{
		s->cs_grade += new_grade - original_grade;
		if (original_grade < 60)
			--s->cs_num_fail;
		else
			--s->cs_num_pass;
		if (new_grade < 60)
			++s->cs_num_fail;
		else
			++s->cs_num_pass;

	}
	else
	{
		s->non_cs_grade += new_grade - original_grade;
		if (original_grade < 60)
			--s->non_cs_num_fail;
		else
			--s->non_cs_num_pass;
		if (new_grade < 60)
			++s->non_cs_num_fail;
		else
			++s->non_cs_num_pass;

	}
}

int num_cs_course(const struct student *s)
{
	return s->cs_num_fail + s->cs_num_pass;
}

int cs_average(const struct student *s)
{
	if (num_cs_course(s) == 0)
		return 0;
	return s->cs_grade / num_cs_course(s);
}


int num_fail_course(const struct student *s)
{
	return (s->cs_num_fail  + s->non_cs_num_fail );
}
int num_pass_course(const struct student *s)
{
	return (s->cs_num_pass  + s->non_cs_num_pass);
}

int num_course(const struct student *s)
{
	return (s->cs_num_fail + s->cs_num_pass + s->non_cs_num_fail + s->non_cs_num_pass);
}

int total_grade(const struct student *s)
{
	return s->cs_grade + s->non_cs_grade;
}


int cav(const struct student *s)
{
	if (num_course(s) == 0)
		return 0;
	return  total_grade(s) / num_course(s);
}

void print_status(const struct student *s)
{
	if (num_course(s) == 0)
		printf("NONE\n");
	else if (num_fail_course(s) > 4 || num_fail_course(s) > num_pass_course(s))
		printf("FRW\n");
	else if (num_cs_course(s) ==0)
		printf("NOCS\n");
	else if (cs_average(s) < 60 && cav(s)<60 )
		printf("FLPP\n");
	else if (cav(s)<60)
		printf("PRBO\n");
	else if (cs_average(s) < 60)
		printf("CNDP\n");
	else if (cav(s) >= 60 && cav(s) < 80)
		printf("GOOD\n");
	else if (cav(s) >= 80)
		printf("EXCL\n");
}

void print_student(const struct student *s)
{
	printf("Student: %d,",s->id);
	printf(" CS_AVG: %d,", cav(s));
	printf(" Failures: %d,", num_fail_course(s));
	printf(" Status: ");
	print_status(s);
}

bool student_equals(const struct student *s1, const struct student *s2)
{
	return (
		s1->id == s2->id && 
		s1->cs_grade == s2->cs_grade &&
		s1->cs_num_fail == s2->cs_num_fail &&
		s1->cs_num_pass == s2->cs_num_pass &&
		s1->non_cs_grade == s2->non_cs_grade &&
		s1->non_cs_num_fail == s2->non_cs_num_fail &&
		s1->non_cs_num_pass == s2->non_cs_num_pass
		);
}


bool can_graduate(const struct student *s)
{
	return (num_pass_course(s) >= 40 && num_cs_course(s) >= 15 && cav(s) >= 60);
}




//int _tmain(int argc, _TCHAR* argv[])
//{
//	struct student s = { 12345 };
//	initialize_new_student(&s);
//	print_status(&s);
//	print_student(&s);
//	assert(student_equals(&s, &s));
//	take_course(&s, 70, true);
//	take_course(&s, 72, false);
//	adjust_grade(&s, 72, 73, false);
//	assert(cs_average(&s) == 70);
//	assert(cav(&s) == 71);
//	assert(!can_graduate(&s));
//	getchar();
//	return 0;
//}
