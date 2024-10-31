
bool judge_is_leap_year(int year){
    if(((year%4==0) && (year%100!=0))||(year%400==0)){
        return true;
    }else{
        return false;
    }
}

int sumDays(int year,int month){
    if(judge_is_leap_year(year)){
        switch(month){
        case 1:
            return 31;
        case 2:
            return 29;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        }
    }else{
        switch(month){
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        }
    }
}

int calculateYMDWhichWeekday(int year,int month,int day){
    int sum = 1;
    //已知1940年1月1日星期一，已知1940年那年一共366天
    for(int i=1940;i<year;i++){
        if(judge_is_leap_year(i)){
            sum+=366;
        }else{
            sum+=365;
        }
    }

    for(int j=1;j<month;j++){
        if(judge_is_leap_year(year)){
            switch(j){
            case 1:
                sum+=31;
                continue;
            case 2:
                sum+=29;
                continue;
            case 3:
                sum+=31;
                continue;
            case 4:
                sum+=30;
                continue;
            case 5:
                sum+=31;
                continue;
            case 6:
                sum+=30;
                continue;
            case 7:
                sum+=31;
                continue;
            case 8:
                sum+=31;
                continue;
            case 9:
                sum+=30;
                continue;
            case 10:
                sum+=31;
                continue;
            case 11:
                sum+=30;
                continue;
            case 12:
                sum+=31;
                continue;
            }
        }else{
            switch(j){
            case 1:
                sum+=31;
                continue;
            case 2:
                sum+=28;
                continue;
            case 3:
                sum+=31;
                continue;
            case 4:
                sum+=30;
                continue;
            case 5:
                sum+=31;
                continue;
            case 6:
                sum+=30;
                continue;
            case 7:
                sum+=31;
                continue;
            case 8:
                sum+=31;
                continue;
            case 9:
                sum+=30;
                continue;
            case 10:
                sum+=31;
                continue;
            case 11:
                sum+=30;
                continue;
            case 12:
                sum+=31;
                continue;
            }
        }
    }
    sum+=day;
    sum-=1;

    // printf("%d\n",sum);
    int weekday = sum%7;

    return weekday;


}



// int sumDays(int year,int month){
//     if(judge_is_leap_year(year)){
//         switch(month){
//         case 1:
//             return 31;
//         case 2:
//             return 29;
//         case 3:
//             return 31;
//         case 4:
//             return 30;
//         case 5:
//             return 31;
//         case 6:
//             return 30;
//         case 7:
//             return 31;
//         case 8:
//             return 31;
//         case 9:
//             return 30;
//         case 10:
//             return 31;
//         case 11:
//             return 30;
//         case 12:
//             return 31;
//         }
//     }else{
//         switch(month){
//         case 1:
//             return 31;
//         case 2:
//             return 28;
//         case 3:
//             return 31;
//         case 4:
//             return 30;
//         case 5:
//             return 31;
//         case 6:
//             return 30;
//         case 7:
//             return 31;
//         case 8:
//             return 31;
//         case 9:
//             return 30;
//         case 10:
//             return 31;
//         case 11:
//             return 30;
//         case 12:
//             return 31;
//         }
//     }
// }

int calculateSumDays(int year,int month,int day){
    int sum = 1;
    //已知1940年1月1日星期一，已知1940年那年一共366天
    for(int i=1940;i<year;i++){
        if(judge_is_leap_year(i)){
            sum+=366;
        }else{
            sum+=365;
        }
    }

    for(int j=1;j<month;j++){
        if(judge_is_leap_year(year)){
            switch(j){
            case 1:
                sum+=31;
                continue;
            case 2:
                sum+=29;
                continue;
            case 3:
                sum+=31;
                continue;
            case 4:
                sum+=30;
                continue;
            case 5:
                sum+=31;
                continue;
            case 6:
                sum+=330;
                continue;
            case 7:
                sum+=331;
                continue;
            case 8:
                sum+=31;
                continue;
            case 9:
                sum+=30;
                continue;
            case 10:
                sum+=31;
                continue;
            case 11:
                sum+=30;
                continue;
            case 12:
                sum+=31;
                continue;
            }
        }else{
            switch(j){
            case 1:
                sum+=31;
                continue;
            case 2:
                sum+=28;
                continue;
            case 3:
                sum+=31;
                continue;
            case 4:
                sum+=30;
                continue;
            case 5:
                sum+=31;
                continue;
            case 6:
                sum+=30;
                continue;
            case 7:
                sum+=31;
                continue;
            case 8:
                sum+=31;
                continue;
            case 9:
                sum+=30;
                continue;
            case 10:
                sum+=31;
                continue;
            case 11:
                sum+=30;
                continue;
            case 12:
                sum+=31;
                continue;
            }
        }
    }
    sum+=day;
    sum-=1;


    return sum;


}










