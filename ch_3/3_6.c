#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum Type {Pet, Cat, Dog} type;

struct Pet {
        int num;
        enum Type type;
        struct Pet *next_pet;
        struct Pet *prev_pet;
        struct Pet *next_spec;
        struct Pet *prev_spec;
};

struct Queue {
        size_t length;
        struct Pet *head;
        struct Pet *tail;
};

struct Pet *make_pet(enum Type type, int num)
{
        struct Pet *new_pet = malloc(sizeof(struct Pet));
        if (!new_pet)
                exit(1);
        new_pet->type = type;
        new_pet->num = num;
        return new_pet;
}

struct Queue *make_queue()
{
        struct Queue *new_queue = malloc(sizeof(struct Queue));
        if (! new_queue)
                exit(1);
        return new_queue;
}

void enque(struct Pet *pet, struct Queue *pet_queue, struct Queue *cat_queue, struct Queue *dog_queue)
{
        struct Queue *spec_queue = pet->type == Cat ? cat_queue : dog_queue;
        pet->prev_pet = NULL;
        pet->prev_spec = NULL;
        if (!pet_queue->head) {
                pet_queue->head = pet;
                pet_queue->tail = pet;
        } else {
                pet->next_pet = pet_queue->head;
                pet_queue->head->prev_pet = pet;
                pet_queue->head = pet;
        }

        if (!spec_queue->head) {
                spec_queue->head = pet;
                spec_queue->tail = pet;
        } else {
                pet->next_spec = spec_queue->head;
                spec_queue->head->prev_spec = pet;
                spec_queue->head = pet;
        }

        pet_queue->length++;
        spec_queue->length++;
}


void print_queue(struct Queue *queue, enum Type type, bool bw)
{
        struct Pet *current_pet = bw ? queue->tail : queue->head;
        while(current_pet) {
                printf("%d->", current_pet->num);
                if (type == Pet)
                        current_pet = bw ? current_pet->prev_pet : current_pet->next_pet;
                else
                        current_pet = bw ? current_pet->prev_spec : current_pet->next_spec;
        }
        puts("");
}

int main() {
        struct Queue *pet_queue = make_queue();
        struct Queue *dog_queue = make_queue();
        struct Queue *cat_queue = make_queue();

        struct Pet *dog1 = make_pet(Dog, 1);
        struct Pet *dog2 = make_pet(Dog, 2);
        enque(dog1, pet_queue, cat_queue, dog_queue);
        enque(dog2, pet_queue, cat_queue, dog_queue);

        struct Pet *cat1 = make_pet(Cat, 3);
        struct Pet *cat2 = make_pet(Cat, 4);
        enque(cat1, pet_queue, cat_queue, dog_queue);
        enque(cat2, pet_queue, cat_queue, dog_queue);
       
        puts("pet_queue:");
        print_queue(pet_queue, Pet, true);
        puts("cat_queue:");
        print_queue(cat_queue, Cat, true);
        puts("dog_queue");
        print_queue(dog_queue, Dog, true);

        return 0;
}
