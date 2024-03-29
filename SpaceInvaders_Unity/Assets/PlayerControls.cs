using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerControls : MonoBehaviour 
{
    public Animator anim;

	public float moveSpeed = 5;
    public GameObject dragon;
    AudioSource shoot;

    public int lives;
    public Text livesText;
    public int score;
    public Text scoreText;

	// Use this for initialization
	void Start () 
	{
        anim = GetComponent<Animator>();
        shoot = GetComponent<AudioSource>();
        lives = 3;
        livesText.text = "Lives: " + lives.ToString();
        score = 0;
        scoreText.text = "Score: " + score.ToString();
	}
	
	// Update is called once per frame
	void Update () 
	{
        //move left and right if arrows are pressed
		if (Input.GetKey (KeyCode.LeftArrow)) 
		{
			transform.Translate (new Vector3 (-moveSpeed * Time.deltaTime, 0, 0));
            anim.SetBool("walking", true);

		} 
		else if (Input.GetKey (KeyCode.RightArrow)) 
		{
			transform.Translate (new Vector3 (moveSpeed * Time.deltaTime, 0, 0));
            anim.SetBool("walking", true);
        }
        else
        {
            anim.SetBool("walking", false);
        }

        //create a bullet and play a sound when spacebar is pressed
        if (Input.GetKeyDown(KeyCode.Space))
        {
            GameObject dragon = Instantiate(Resources.Load("dragon"), transform.position, transform.rotation) as GameObject;
            shoot.Play();
        }

        //keep from going off screen
		if (transform.position.x <= -10)
			transform.position = new Vector3 (-10, transform.position.y, transform.position.z);
		if (transform.position.x >= 10)
			transform.position = new Vector3 (10, transform.position.y, transform.position.z);
	}

    private void OnCollisionEnter2D(Collision2D collision)
    {
        //Play death animation, then terminate if touched by an enemy
        if (collision.gameObject.tag == "Enemy")
        {
            anim.SetBool("hit", true);
            lives -= 1;
            livesText.text = "Lives: " + lives.ToString();
            scoreText.text = "Score: " + score.ToString();

            if (lives <= 0)
            {
                SceneManager.LoadScene(2);
            }
        }
    }
}