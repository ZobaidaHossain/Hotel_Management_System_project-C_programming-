#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Room_Reservation
{
    char Name[50];
    int Number_Of_Guests;
    int Duration_Of_Stay;
    char Mobile_Number[20];
    char Room_Type[20];
    int cost;
    struct Room_Reservation *next;

} node;

node *head = NULL;
node *temp = NULL;
node *prev = NULL;

int Stdrd = 0;
int Pre = 0;
int vip = 0;

void ShowDetails_Rooms()
{
    printf("Rooms Available: 20\n\n");

    printf("Room Type: Standard\n");
    printf("Available: %d\n", 10 - Stdrd);
    printf("Capacity: 04 Persons\n");
    printf("Price For 1 Night 1 Day: 2500 BDT\n\n");

    printf("Room Type: Premium\n");
    printf("Available: %d\n", 5 - Pre);
    printf("Capacity: 02\n");
    printf("Price For 1 Night 1 Day: 5000 BDT\n\n");

    printf("Room Type: VIP\n");
    printf("Available: %d\n", 5 - vip);
    printf("Capacity: 02\n");
    printf("Price For 1 Night 1 Day: 10000 BDT\n\n");

}
void Reserve_Room()
{
    node *n1 = (node*)malloc(sizeof(node));

    n1->cost = 0;
    printf("Enter Your Name: \n");
    scanf(" %s", n1->Name);
    printf("Enter Number of Guests: \n");
    scanf("%d", &n1->Number_Of_Guests);
    printf("How Many Days You Want To Stay Here? \n");
    scanf("%d", &n1->Duration_Of_Stay);
    printf("Enter Your Mobile Number: \n");
    scanf(" %s", n1->Mobile_Number);
    ShowDetails_Rooms();
    printf("Enter Your Chosen Room: \n");
    scanf(" %s", n1->Room_Type);
    if(strcmp(n1->Room_Type, "Premium") == 0)
    {
        if(Pre == 5)
        {
            printf("\nSorry!Premium Rooms Are Not Available. Choose Another One\n\n");
            scanf(" %s", n1->Room_Type);
        }
        else
        {
            Pre++;
            n1->cost = n1->cost + (n1->Duration_Of_Stay * 2500);
        }
    }
    else if(strcasecmp(n1->Room_Type, "Standard") == 0)
    {
        if(Stdrd == 10)
        {
            printf("\nSorry!Premium Rooms Are Not Available. Choose Another One\n\n");
            scanf(" %s", n1->Room_Type);
        }
        else
        {
            Stdrd++;
            n1->cost = n1->cost + (n1->Duration_Of_Stay * 5000);
        }
    }
    else
    {
        if(vip == 5)
        {
            printf("\nSorry!Premium Rooms Are Not Available. Choose Another One\n\n");
            scanf(" %s", n1->Room_Type);
        }
        else
        {
            vip++;
            n1->cost = n1->cost + (n1->Duration_Of_Stay * 10000);
        }

    }

    n1->next = NULL;

    if(head == NULL)
    {
        head = n1;
    }

    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n1;
    }

}
void Show_Reservation_Details()
{
    if(head == NULL)
        printf("\nNo Details Found!!\nYou Have Not Reserve Any Room Yet\n\n");
    else
    {
        int count = 1;
        temp = head;
        while(temp != NULL)
        {
            printf("Reservation: %d\n", count);
            printf(" Name: %s\n",temp->Name);
            printf(" Number Of Guests Staying: %d\n",temp->Number_Of_Guests);
            printf(" Duration Of Stay: %d\n",temp->Duration_Of_Stay);
            printf(" Mobile Number: %s\n", temp->Mobile_Number);
            printf(" Room Type: %s\n",temp->Room_Type);
            printf("Total Cost: %d\n", temp->cost);
            printf("\n");
            temp = temp->next;
            count++;
        }
    }
}
void Update_Reservation()
{
    int choose, Flag = 0, new_stay;
    char new_room[50];
    char old_name[100];
    char new_name[100];
    char new_num[20];
    printf("Press 1: Update Your Name\n");
    printf("Press 2: Update Your Mobile Number\n");
    printf("Press 3: Update Your Duration Of Stay\n");
    printf("Press 4: Update Your Room Type\n");
    scanf("%d", &choose);

    for(int i = 0; i<3; i++)
    {
        printf("Enter Your Name: ");
        scanf("%s", old_name);
        temp = head;
        while(temp != NULL)
        {
            if(strcmp(old_name, temp->Name) == 0)
            {
                if(choose ==1)
                {
                    printf("Enter Your New Name: ");
                    scanf("%s", new_name);
                    strcpy(temp->Name, new_name);
                    printf("\nName Has Been Updated\n\n");
                }
                else if(choose == 2)
                {
                    printf("Enter Your New Mobile Number: ");
                    scanf("%s", new_num);
                    strcpy(temp->Mobile_Number, new_num);
                    printf("\nMobile Number Has Been Updated\n\n");
                }
                else if(choose == 3)
                {
                    printf("Enter How Many Days Are You Going To Stay: ");
                    scanf("%d", &new_stay);
                    temp->Duration_Of_Stay = new_stay;
                    printf("\nYour Duration Of Stay Has Been Updated\n\n");
                }
                else if(choose == 4)
                {
                    printf("Enter Your Desired Room Type: ");
                    scanf("%s", new_room);
                    strcpy(temp->Room_Type, new_room);
                    printf("\nYour Desired Room Has Been Reserved For You.\n\n");
                }
                printf("\nUpdated Information Of The Client: \n\n");
                printf(" Name: %s\n",temp->Name);
                printf(" Number Of Guests Staying: %d\n",temp->Number_Of_Guests);
                printf(" Duration Of Stay: %d\n",temp->Duration_Of_Stay);
                printf(" Mobile Number: %s\n", temp->Mobile_Number);
                printf(" Room Type: %s\n",temp->Room_Type);
                printf("Total Cost: %d\n", temp->cost);
                printf("\n");
                Flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(Flag == 1)
            break;

        else if(i == 2)
            printf("Sorry!! You Have Reached To The Max Try.\n\n");
        else
            printf("\nData Not Found. Try Again\n");

    }
}
void Delete_Reservation(char Name[])
{

    temp = head;
    if(strcmp(head->Name, Name) == 0)
    {
        head = head->next;
        free(temp);
        if(strcmp(head->Room_Type, "Standard") == 0)
            Stdrd--;
        else if(strcmp(head->Room_Type, "Premium") == 0)
            Pre--;
        else
            vip--;
        printf("\n\nYour Reservation Has been Canceled. Thank You. Come Again.\n");
    }
    else
    {
        temp = head;
        while(temp != NULL && strcmp(Name, temp->Name) != 0)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
            printf("Your Name Has Not found in the list\n\n");

        else
        {
            if(strcmp(head->Room_Type, "Standard") == 0)
                Stdrd--;
            else if(strcmp(head->Room_Type, "Premium") == 0)
                Pre--;
            else
                vip--;
            prev->next = temp->next;
            free(temp);
            printf("\n\nYour Reservation Has been Canceled. Thank You. Come Again.\n");
        }
    }

}
void Services()
{
    int service, people, choice, Flag = 0;
    char old_name[100];

    printf("Available Services: \n\n");
    printf("1. Room Cleaning \n");
    printf("2. Food Delivery \n");
    printf("3. Extra Blanket/Pillow \n");
    printf("4. Laundry \n");
    printf("5. Car Rental \n");

    printf("\nChoose What Do You Need: \n");
    scanf("%d",&service);

    if(service == 1 || service == 4)
    {
        printf("Your Service Request Has Been Received\n Thank You For Your Precious Time. \n");

    }
    else if(service == 2)
    {
        for(int i = 0; i<3; i++)
        {
            printf("Enter Your Name: ");
            scanf("%s", old_name);

            temp = head;
            while(temp != NULL)
            {
                if(strcmp(old_name, temp->Name) == 0)
                {
                    printf("\n\nFood Menu:\n");
                    printf("1. Mexican Food Price: 500 TK/Plate\n");
                    printf("2. Italian Food Price: 700TK/Plate\n");
                    printf("3. Chinese Food  Price: 400 TK/Plate\n");
                    printf("4. Thai Food price: 600 TK/Plate\n");
                    printf("\nEnter Your choice\n");
                    scanf("%d", &choice);
                    printf("For How Many People Would You Like To Order Food?\n");
                    scanf("%d", &people);

                    if(choice == 1)
                    {
                        temp->cost = temp->cost + (500 * people);
                    }
                    else if(choice == 2)
                    {
                        temp->cost = temp->cost + (700 * people);
                    }
                    else if(choice == 3)
                    {
                        temp->cost = temp->cost + (400 * people);
                    }
                    else if(choice == 4)
                    {
                        temp->cost = temp->cost + (600 * people);
                    }

                    Flag = 1;
                    break;

                }

                temp = temp->next;

            }
            if (Flag == 1)
            {
                printf("\nYour Service Request Has Been Received.\nYour Ordered Food Will Be Delivered Soon. Thank You For Your Precious Time.\n");
                break;
            }
            if(i == 2)
                printf("\n\nSorry! You Have Reached To Your Max Try.\n\n");
            else
                printf("\nData Not Found In The Reservation List. Try Again\n");
        }

    }
    else if(service == 3)
    {
        printf("Enter The Number Of Blankets: ");
        scanf("%d", &people);
        printf("Your Service Request Has Been Received\n Thank You For Your Precious Time. \n");
    }

    else if(service == 5)
    {
        printf("Available Cars:\n");
        printf("1. Toyota Axio\n  Total Seat: 5\n  Price: 2500TK/Day\n\n");
        printf("2.Toyota Premio\n  Total Seat: 5\n  Price: 3500TK/Day\n\n");
        printf("3.Toyota Noah Hybrid\n  Total Seat: 12\n  Price: 5500TK/Day\n\n");
        printf("\nWhich Car You Want To Rent?\nEnter Your Choice\n");
        scanf("%d", &choice);

        for(int i = 0; i<3; i++)
        {
            printf("Enter Your Name: ");
            scanf("%s", old_name);

            temp = head;
            while(temp != NULL)
            {
                if(strcmp(old_name, temp->Name) == 0)
                {
                    if(choice == 1)
                    {
                        temp->cost = temp->cost + 2500;
                    }
                    else if(choice == 2)
                    {
                        temp->cost = temp->cost + 3500;
                    }
                    else if(choice == 3)
                    {
                        temp->cost = temp->cost + 5500;
                    }

                    Flag = 1;
                    break;

                }

                temp = temp->next;

            }
            if (Flag == 1)
            {
                printf("\nYour Service Request Has Been Received.\nYour Ordered Food Will Be Delivered Soon. Thank You For Your Precious Time.\n");
                break;
            }
            if(i == 2)
                printf("\n\nSorry! You Have Reached To Your Max Try.\n\n");
            else
                printf("\nData Not Found In the Reservation List. Try Again\n");
        }


    }

}

int main ()
{
    int choice, Selection;
    printf("\t\t\t\t _____________________________________\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t|*************************************|\n");
    printf("\t\t\t\t|********WELCOME TO FIAO HOTEL********|\n");
    printf("\t\t\t\t|*************************************|\n");
    printf("\t\t\t\t|_____________________________________|\n");
    printf("\n");
    printf("----------------------------------------------------------------------------------------------------------");
    printf("\n\n");
    for(int i=0;; i++)
    {
        printf("\nAvailable Services:\n\n");
        printf("1. Details Of Rooms \n");
        printf("2. Reserve A Room For Yourself \n");
        printf("3. Reservation Details \n");
        printf("4. Show Services \n");
        printf("5. Update Your Reservation \n");
        printf("6. Cancel Your Reservation \n");
        printf("\n\n!!!Choose Your Needed Query: !!!\n");
        scanf("%d",&Selection);

        if(Selection==1)
        {
            ShowDetails_Rooms();
        }
        else if(Selection==2)
        {
            int n;
            printf("How Many Reservations You Want to Make?\n");
            scanf("%d", &n);
            for(int i = 0; i<n; i++)
            {
                printf("\nEnter The Info Of client: %d \n", i+1);
                Reserve_Room();
            }

            printf("\n\nYour Reservation Has been Done.\n\n");
            Show_Reservation_Details();
            printf("\n\nThank You For Precious Time.\n\n");
        }
        else if(Selection==3)
        {
            Show_Reservation_Details();
        }
        else if(Selection==4)
        {
            Services();
        }

        else if(Selection==5)
        {
            Update_Reservation();
        }

        else if(Selection==6)
        {
            printf("Enter Your Name: ");
            char Name[50];
            scanf(" %s", Name);
            Delete_Reservation(Name);
        }
        printf("\nDo You Want To Continue ?\n");
        printf("1. Yes \n2. No\n");
        scanf("%d",&choice);
        if(choice == 2)
        {
            printf("Thank You For Your Precious Time \n");
            break;
        }
    }

    return 0;
}

