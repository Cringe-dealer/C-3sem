#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "file_tools.h"
#include "tools.h"
#include "deletion.h"


START_TEST(test_ordinary)
{
    node_t *head = NULL;
    FILE *f = fopen("unit_tests/3_el.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                pop_back(&head);

                song_t song = { "Queen", "Bohemian Rhapsody" };
                ck_assert_int_eq(comparator(&song, head->data), 0);
                song_t song1 = { "Coldplay", "Viva La Vida" };
                ck_assert_int_eq(comparator(&song1, head->next->data), 0);

                list_free(head);
            }
            songs_free(songs);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_one_el)
{
    node_t *head = NULL;
    FILE *f = fopen("unit_tests/1_el.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                pop_back(&head);

                ck_assert_ptr_eq(head, NULL);
            }
            songs_free(songs);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_empty_ptr)
{
    node_t *head = NULL;
    void *ptr;

    ptr = pop_back(&head);

    ck_assert_ptr_eq(head, NULL);
    ck_assert_ptr_eq(ptr, NULL);
}
END_TEST


Suite* pop_back_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("pop_back");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_empty_ptr);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    tcase_add_test(tc_pos, test_one_el);
    suite_add_tcase(s, tc_pos);

    return s;
}
