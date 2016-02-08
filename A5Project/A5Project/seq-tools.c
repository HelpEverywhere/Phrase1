#include <stdio.h>
#include "sequence.h"
#include "seq-tools.h"


// INTEGRITY STATEMENT (modify if necessary)
// I received help from the following sources:
// None. I am the sole author of this work 

// sign this statement by removing the line below and entering your name
//ERROR_I_have_NOT_yet_completed_the_INTEGRITY_statement
// Name:
// login ID:

// implementation:


void Sequence_add_one(struct Sequence *seq) {
	int pos = 0;
	while (pos< Sequence_length(seq))
	{
		int item = Sequence_remove_at(seq, pos);
		Sequence_insert_at(seq, pos, ++item);
		++pos;
	}
}


struct Sequence *Sequence_build(int n) {
	struct Sequence *seq = Sequence_create();
	int pos = 0;
	while (pos< Sequence_length(seq))
	{
		Sequence_insert_at(seq, pos, pos);
		++pos;
	}
	return seq;
}


void Sequence_map(int (*fp)(int), struct Sequence *seq) {
	int pos = 0;
	while (pos< Sequence_length(seq))
	{
		int item = Sequence_remove_at(seq, pos);
		Sequence_insert_at(seq, pos, (*fp)(item));
		++pos;
	}
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


bool Sequence_equal(const struct Sequence *seq1, const struct Sequence *seq2) {
	if (Sequence_length(seq1) == Sequence_length(seq2))
	{
		int pos = 0;
		while (pos< Sequence_length(seq1))
		{
			if (Sequence_item_at(seq1, pos) != Sequence_item_at(seq2, pos))
				return false;
			++pos;
		}
		return true;
	}
	return false;
}


void Sequence_add_sum(struct Sequence *seq) {
	int pos = 0,sum=0;
	while (pos< Sequence_length(seq))
	{
		int item = Sequence_remove_at(seq, pos);
		sum += item;
		Sequence_insert_at(seq, pos, sum);
		++pos;
	}

}


void Sequence_avg_and_variance(const struct Sequence *seq, 
                               int *avg, int *var) 
{
	int pos = 0, sum = 0, len = Sequence_length(seq);
	while (pos< len)
	{
		int item = Sequence_item_at(seq, pos);
		sum += item;
		++pos;
	}
	pos = 0;
	*avg = sum / len;

	int var_sum = 0;
	while (pos< len)
	{
		int item = Sequence_item_at(seq, pos);
		var_sum += (item - (*avg)) * (item - (*avg));
		++pos;
	}
	*var = var_sum / len;

}


void Sequence_filter(bool (*fp)(int), struct Sequence *seq) {
	int pos = 0;
	while (pos< Sequence_length(seq))
	{
		int item = Sequence_item_at(seq, pos);
		if (!(*fp)(item))
		{
			Sequence_remove_at(seq, pos);
		}
		else
		{
			++pos;
		}
	}

}


int Sequence_foldl(int (*fp)(int, int), int base, 
                   const struct Sequence *seq) {
	return 0;
	//int len = Sequence_length(seq);
	//if (len == 0)
	//	return base;
	//int pos = 0;
	//while (pos < Sequence_length(seq))
	//{
	//	int item = Sequence_item_at(seq, len-pos-1);
	//	(*fp)(item, int)
	//	++pos;
	//}

}


struct Sequence *Sequence_fib(int n) {
	struct Sequence *seq= Sequence_create();
	int pos = 0, n1 = 0, n2 = 1;
	while (pos<n)
	{
		if (pos < 2)
		{
			Sequence_insert_at(seq, pos, pos);
		}
		else
		{
			Sequence_insert_at(seq, pos, n1+n2);
			n1 = n2;
			n2 = n1 + n2;
		}
		++pos;
	}
}


struct Sequence *Sequence_collatz(int n) {
  return Sequence_create();
}


void Sequence_reverse(struct Sequence *seq) {
	int len = Sequence_length(seq);
	if (len > 1)
	{
		int pos = 0;
		while (pos < len / 2)
		{
			int item1 = Sequence_remove_at(seq, pos);
			int item2 = Sequence_remove_at(seq, len-pos-2);

			Sequence_insert_at(seq, pos, item2);
			Sequence_insert_at(seq, len - pos - 2, item1);

			++pos;

		}
	}
}
