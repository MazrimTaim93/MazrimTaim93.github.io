using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletMovement : MonoBehaviour {

    public float moveSpeed = 8;
    AudioSource hit;

    public GameObject player;
    public PlayerControls pControls;

    // Use this for initialization
    void Start ()
    {
        //destroy after 1 second
        Destroy(gameObject, 1.3f);
        hit = GetComponent<AudioSource>();
        player = GameObject.Find("khaleesi spaceship");
        pControls = player.GetComponent<PlayerControls>();
    }
	
	// Update is called once per frame
	void Update ()
    {
        //move straight up
        transform.Translate(new Vector3(0, moveSpeed * Time.deltaTime, 0));
	}

    private void OnCollisionEnter2D(Collision2D collision)
    {
        //Destroy bullet, unless its just touching the parent object
        if (collision.gameObject.tag != "Player")
        {
            hit.Play();
            if (collision.gameObject.tag == "Enemy")
            {
                pControls.score += 10;
                pControls.scoreText.text = "Score: " + pControls.score.ToString();
            }
            Destroy(gameObject, 0.3f);
        }
    }
}
