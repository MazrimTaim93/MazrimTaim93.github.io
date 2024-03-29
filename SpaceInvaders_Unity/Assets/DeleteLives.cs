using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeleteLives : MonoBehaviour {

    public int lives;
    public int playerLives;
    public GameObject player;
    public PlayerControls pControls;

    // Use this for initialization
    void Start ()
    {
        player = GameObject.Find("khaleesi spaceship");
        pControls = player.GetComponent<PlayerControls>();
    }
	
	// Update is called once per frame
	void Update ()
    {
        playerLives = pControls.lives;
        if (playerLives <= lives)
        {
            Destroy(gameObject);
        }
	}
}
