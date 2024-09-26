package jp.ac.ait.oop1.k23023;
import jp.ac.ait.oop1.section09.StudentBase;
import jp.ac.ait.oop1.section09.Grade;
import jp.ac.ait.oop1.section09.IStudent;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Student extends StudentBase implements IStudent{

    public Student(String studentId, String name, List<Grade> grades){
        setStudentId(studentId);
        setName(name);
        setGrades(grades);
    }

    @Override
    public List<Grade> getGradesFilterByRating(char rating) {
        List<Grade> filterdList = new ArrayList<>();
        getGrades().stream().filter(item -> item.getMyRating() == rating).forEach(item -> filterdList.add(item));
        return filterdList;
    }
    @Override
    public List<Grade> getGradesSortByRatingDsc(){

        List<Grade> sortedList = new ArrayList<>(getGrades());
        sortedList.sort(Comparator.comparingInt(obj -> {
            char c = ((Grade)obj).getMyRating();
            switch (c){
                case 'S':
                    return 0;
                case 'A':
                    return 1;
                case 'B':
                    return 2;
                case 'C':
                    return 3;
                case 'F':
                    return 4;
                case 'Q':
                    return 5;
                default:
                    return Integer.MAX_VALUE;
            }

        }).thenComparing(obj -> ((Grade)obj).getSubject()));//unicodeの並び替えが続く？
        return sortedList;
    }

    @Override
    public List<Grade> getGradesFilterByCreditsEarned() {
        List<Grade> filterdList = new ArrayList<>();
        getGrades().stream().filter(obj -> {
            if(obj.getMyCredit() != 0) return true;
            else return false;
        }).forEach(obj -> filterdList.add(obj));
        return filterdList;
    }

    @Override
    public int getTotalCreditsEarned() {

        int count = 0;
        for(int i=0;i<getGrades().size();i++){
            count += getGrades().get(i).getMyCredit();
        }
        return count;
    }

}
