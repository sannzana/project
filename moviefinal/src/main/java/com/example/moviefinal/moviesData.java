package com.example.moviefinal;

import java.sql.Date;
import java.time.Duration;

public class moviesData {


    private String title;
    private String genre;
    private String duration;
    private Date date;
    private String image;
    private String director;


    public moviesData(String title, String genre, String duration, String image ,Date date,String director) {
       this.title=title;
       this.date=date;
       this.duration=duration;
       this.genre=genre;
       this.image=image;
       this.director=director;

    }



    public String getDuration()
    {
        return duration;

    }
    public String getGenre()
    {
        return genre;

    }
    public String getImage()
    {
        return image;

    }
    public String getTitle()
    {
        return title;

    }
    public String getDirector()
    {
        return director;

    }
    public  Date getDate()
    {
        return date;
    }





}
