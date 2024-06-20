package jp.ac.ait.oop1.k23023;
import jp.ac.ait.oop1.section09.Grade;
import jp.ac.ait.oop1.section09.IStudent;
import jp.ac.ait.oop1.section09.IStudentsSorter;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class StudentsSorter implements IStudentsSorter {
    List<IStudent> students;

    public StudentsSorter(List<IStudent> students){
        setStudents(students);
    }

    @Override
    public List<IStudent> getStudents() {
        return students;
    }

    @Override
    public void setStudents(List<IStudent> students) {
        this.students = students;
    }

    @Override
    public List<IStudent> sortByTotalCreditsEarnedAsc(){//昇順

        List<IStudent> sortedStudents = new ArrayList<>(this.students);
        sortedStudents.sort(new Comparator<IStudent>() {
            @Override
            public int compare(IStudent o1, IStudent o2) {
                return o1.getTotalCreditsEarned() - o2.getTotalCreditsEarned();
            }
        });
        return sortedStudents;

    }
    @Override
    public List<IStudent> sortByTotalCreditsEarnedDsc(){//降順

        List<IStudent> sortedStudents = new ArrayList<>(this.students);
        sortedStudents.sort(new Comparator<IStudent>() {
            @Override
            public int compare(IStudent o1, IStudent o2) {
                return o2.getTotalCreditsEarned() - o1.getTotalCreditsEarned();
            }
        });
        return sortedStudents;
    }


}
