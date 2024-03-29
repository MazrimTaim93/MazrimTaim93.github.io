using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public int playerScore {get; set;}
    public int playerLives { get; set; }
    public Text scoreText;

    private static GameManager _instance;

    public static GameManager Instance
    {
        get
        {
            if (_instance == null)
            {
                GameObject gObject = new GameObject("GameManager");
                gObject.AddComponent<GameManager>();
            }

            return _instance;
        }
    }

    private void Awake()
    {
        _instance = this;

        playerScore = 0;
        scoreText.text = "Score: " + playerScore.ToString();
    }

    private void Update()
    {
        scoreText.text = "Score: " + playerScore.ToString();
    }
}
