package com.example.moviefinal;

import java.sql.Date;
import java.time.Duration;

public class moviesData {

    private String title;
    private String genre;
    private String duration;
    private Date date;
    private String image;


    public moviesData(String title, String genre, String duration, String image ,Date date) {
       this.title=title;
       this.date=date;
       this.duration=duration;
       this.genre=genre;
       this.image=image;

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
    public  Date getDate()
    {
        return date;
    }





}
