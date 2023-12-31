    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void displayMenu() {
        printf("\nText Editor Menu:\n");
        printf("1. Enter Text\n");
        printf("2. Search for Word\n");
        printf("3. Replace Word\n");
        printf("4. Delete\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Delete a Word\n");
        printf("8. Exit\n");
    }
    int main()
    {
        int enter;
        char buffer[256]="";
        char string[258]="";
        char search[100]="";
        char temp[256]="";
        int  j, k, z, num, cif = 0; 
    
        while(1) 
        {
            displayMenu();
            printf("The existing text: %s \n",buffer);
            printf("Enter your choice: ");
            scanf("%d",&enter);
            printf("\n\n");
            char filename[100];
            switch (enter) {
                case 1:
                    printf("Enter the text: ");
                    getchar();
                    fgets(string, sizeof(string), stdin);
                    if(strlen(buffer)+strlen(string)<sizeof(buffer))
                    {
                        strcat(buffer, string); 
                        buffer[strcspn(buffer, "\n")] = 0;
                        strcat(buffer," ");
                    }
                    else
                    {
                        printf("Not enough space");
                    }
                    break;
                case 2:
                    printf("write the word to search: ");
                    getchar();
                    fgets(search, sizeof(search), stdin);
                    search[strcspn(search, "\n")] = 0;
                    cif=0;
                    for(j=0;j<strlen(buffer);j++)
                    {
                        if (buffer[j] == search[0] && (j==0 || buffer[j-1]==' '))
                        {
                            k=j;
                            z=0;
                            num=0;
                            while (buffer[k]==search[z] && z < strlen(search))
                            {
                                num +=1;
                                k++;
                                z++;
                            }
                            if (num == strlen(search) && (j + strlen(search) == strlen(buffer) || buffer[j + strlen(search)] == ' '))
                            {
                                cif++;
                                j += strlen(search)-1;
                            }
                        }
                    }
                    printf("word %s appears %d times",search,cif);
                    break;
                case 3:
                    printf("write the word that must be replaced: ");
                    getchar();
                    fgets(search, sizeof(search), stdin);
                    search[strcspn(search, "\n")] = 0;
                    printf("Write the world to replace with: ");
                    fgets(string, sizeof(string), stdin);
                    string[strcspn(string, "\n")] = 0;
                    if(strlen(string)+strlen(buffer)-strlen(search)<sizeof(buffer))
                    {
                        for(j=0;j<strlen(buffer);j++)
                        {
                            if (buffer[j] == search[0] && (j==0 || buffer[j-1]==' '))
                            {
                                k=j;
                                z=0;
                                num=0;
                                while (buffer[k]==search[z] && z < strlen(search))
                                {
                                    num +=1;
                                    k++;
                                    z++;
                                }
                                if (num == strlen(search) && (j + strlen(search) == strlen(buffer) || buffer[j + strlen(search)] == ' '))
                                {
                                    for(z=0;z<j;z++)
                                    {
                                    temp[z]=buffer[z];
                                    }
                                    temp[j] = '\0';
                                    strcat(temp,string);
                                    strcat(temp, buffer+j+strlen(search));
                                    for(k=0;k<strlen(buffer);k++)
                                    {
                                        buffer[k]='\0';
                                    }
                                    strcpy(buffer, temp);
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("Not enough space");
                    }
                    break;
                case 4:
                    for(k=0;k<strlen(buffer);k++)
                    {
                        buffer[k]='\0';
                    }
                    break;
                case 5:
                    printf("Enter the filename to save the text: ");
                    scanf("%s", filename);
                    FILE *file = fopen(filename, "w");
                    if (file == NULL) 
                    {
                        printf("Failed to open the file for writing.\n");
                    } 
                    else 
                    {
                        fputs(buffer, file);
                        fclose(file);
                        printf("Text saved to %s.\n", filename);
                    }
                    break;
                case 6:
                    printf("Enter the filename to load text from: ");
                    scanf("%s", filename);
                    file = fopen(filename, "r");
                    if (file == NULL) 
                    {
                        printf("Failed to open the file for reading.\n");
                    } 
                    else 
                    {
                        if (fgets(buffer, sizeof(buffer), file) != NULL) 
                        {
                            printf("Text loaded from %s.\n", filename);
                        } 
                        else 
                        {
                            printf("No text found in the file.\n");
                        }
                        fclose(file);
                    }
                    break;
                case 7:
                    printf("write the word that must be deleted: ");
                    getchar();
                    fgets(search, sizeof(search), stdin);
                    search[strcspn(search, "\n")] = 0;
                        for(j=0;j<strlen(buffer);j++)
                        {
                            if (buffer[j] == search[0] && (j==0 || buffer[j-1]==' '))
                            {
                                k=j;
                                z=0;
                                num=0;
                                while (buffer[k]==search[z] && z < strlen(search))
                                {
                                    num +=1;
                                    k++;
                                    z++;
                                }
                                if (num == strlen(search) && (j + strlen(search) == strlen(buffer) || buffer[j + strlen(search)] == ' '))
                                {
                                    for(z=0;z<j;z++)
                                    {
                                    temp[z]=buffer[z];
                                    }
                                    temp[j] = '\0';
                                    strcat(temp, buffer+j+strlen(search)+1);
                                    for(k=0;k<strlen(buffer);k++)
                                    {
                                        buffer[k]='\0';
                                    }
                                    strcpy(buffer, temp);
                                }
                            }
                        }
                    break;
                case 8:
                    return 0;
                default:
                    printf("Invalid choice. Please choose a valid option.\n");
            }
        }
    }
